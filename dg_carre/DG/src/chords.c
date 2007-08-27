#include "dg.h"

typedef struct _ChangeChordRec {
  ActProc actProc;
  void* obj;
  Chord ch;
#ifdef CHORDZ /* add z to struct _ChangeChordRec */
  double x1,y1,x2,y2,z1,z2;
#else
  double x1,y1,x2,y2;
#endif
}* ChangeChordRec;

static int ActAddChord(App a,ActRec ar);
static int ActDelChord(App a,DelRec ar);
static int ActChangeChord(App a,ChangeChordRec ar);

void TlAddChord(View w,int event,double x,double y) {
  struct {
    int bEnh;
    Chord ch;
    double x;
    double y;
  }* d;

  d=w->toolData;
  switch(event) {
    case TL_DISABLE:
      if (d!=NULL) FatalError("Tool()-disable0: fatal error 2");
    case TL_ENABLE:
      break;
    case TL_DBLCLK:
      if (d!=NULL) break;
      break;
    case TL_PRESS:
      if (d!=NULL) break;
      d=Malloc(sizeof(*d));
      d->bEnh=0;
      d->ch=NULL;
      d->x=x;
      d->y=y;
      SetViewFlags(w,w->showFlags | SHW_CHORDS);
      break;
    case TL_MOTION:
      if (d==NULL) break;
      if (!d->bEnh) {
        if (d->ch==NULL) {
          d->ch=AddChord(w->app,d->x,d->y,x,y);
          if (d->ch==NULL) break;
          SetHighlightMode(w->app,1);
          Highlight(w,d->ch,1);
        } else {
          ChangeChord(w->app,d->ch,d->ch->x1,d->ch->y1,x,y);
        }
      SetExamineMsg(w,d->ch);
      }
      break;
    case TL_RELEASE:
      if (d==NULL) break;
      UnhighlightAll(w);
      if (!d->bEnh) {
        UndoMark(w->app);
      }
      if (w->app->highlightMode) ViewMsgEx(w,0,NULL);
      d=Free(d);
      break;
    case TL_ENTER:
    case TL_LEAVE:
      if (d==NULL) break;
      if (!d->bEnh) {
        Highlight(w,d->ch,event==TL_ENTER);
      }
      break;
    case TL_CANCEL:
      if (d==NULL) break;
      d=Free(d);
      Cancel(w->app);
      ViewMsgEx(w,MSG_CANCELED,NULL);
      break;
  }
  FlushView(w);
  w->toolData=d;
}

#ifdef CHORDEXT /* define TlExtChord */
void TlExtChord(View w,int event,double x,double y) {
  struct {
    int bEnh,hm;
    Group g;
    Chord ch;
  }* d;
  void* p = NULL;
  Group g;
  MeshPoint mpt;
  MeshCell mc;
  Index ix;
  int i;

  d=w->toolData;
  switch(event) {
    case TL_DISABLE:
      if (d!=NULL) FatalError("Tool()-disable0: fatal error 2");
    case TL_ENABLE:
      break;
    case TL_DBLCLK:
      if (d!=NULL) break;
      break;
    case TL_PRESS:
      if (d!=NULL) break;
      d=Malloc(sizeof(*d));
      d->bEnh=0;
      d->hm=1;
      d->ch=NULL;
      SetViewFlags(w,w->showFlags | SHW_CHORDS);
      p=HitViewObject(w,x,y,SHW_CHORDS);
      if (p==NULL) {
        d=Free(d);
        break;
      }

    case TL_MOTION:
      if (d==NULL) break;
      if (d->bEnh) {
      } else {
        if (d->ch!=NULL) p=HitViewObject(w,x,y,SHW_CHORDS);

        if (p==NULL || p==d->ch) break;
        d->ch=p;

        UnhighlightAll(w);
        SetHighlightMode(w->app,1);
      }
      break;

    case TL_RELEASE:
      if (d==NULL) break;
      if (d->bEnh) {
      } else {
        if (d->ch!=NULL) /* eventually replace this with an error thing */
	  if (ExtendChord(w->app,d->ch))
	    SetViewMsg(w,GetStr(w,ERR_NOELEMSINPATH));
      }
      UnhighlightAll(w);
      UndoMark(w->app);
      d=Free(d);
      break;
    case TL_ENTER:
    case TL_LEAVE:
      if (d==NULL) break;
      if (d->hm) SetHighlightMode(w->app,event==TL_ENTER);
      break;
    case TL_CANCEL:
      if (d==NULL) break;
      if (d->bEnh) {
      }
      d=Free(d);
      ViewMsgEx(w,MSG_CANCELED,NULL);
      Cancel(w->app);
      break;
  }
  FlushView(w);
  w->toolData=d;
}
#endif


Chord AddChord(App a,double x1,double y1,double x2,double y2) {
  Chord ch;
  struct _ActRec ar;

  if (x1==x2 && y1==y2) return NULL;

  ch=Malloc(sizeof(*ch));

  ch->type=T_CHORD;
  ch->locks=0;
  ch->x1=x1;
  ch->y1=y1;
  ch->x2=x2;
  ch->y2=y2;
#ifdef CHORDZ /* initialize dummy z in AddChord */
  ch->z1=0;
  ch->z2=0;
#endif
  ch->vars=ch->varsContaining=NULL;

  ar.obj=ch;
  ActAddChord(a,&ar);

  return ch;
}

int ChangeChord(App a,Chord ch,double x1,double y1,double x2,double y2) {
  struct _ChangeChordRec ar;

  ar.ch=ch;
  ar.x1=x1;
  ar.y1=y1;
  ar.x2=x2;
  ar.y2=y2;
#ifdef CHORDZ /* initialize dummy z in ChangeChord */
  ar.z1=ch->z1;
  ar.z2=ch->z2;
#endif

  ActChangeChord(a,&ar);

  return 0;
}

void* DelChord(App a,Chord ch) {
  struct _DelRec ar;
  Var v;
  Index ix;

  assert(!IsHighlighted(a,ch));
  MarkObject(a,ch,0);

  for (v=Group1st(ch->vars,&ix);v!=NULL;v=Next(&ix))
    SetVar(a,ch,v->def,v->varSet,NULL);

  for (v=Group1st(ch->varsContaining,&ix);v!=NULL;v=Next(&ix))
    ChangeVarEx(a,v,ch,0);

  ar.delete=ch;

  ActDelChord(a,&ar);

  return NULL;
}

#ifdef CHORDZ /* define AddChord3D, ChangeChord3D, and DrawChord3D */
Chord AddChord3D(App a,double x1,double y1,double x2,double y2,double z1,
    double z2) {
  Chord ch;
  struct _ActRec ar;

  if (x1==x2 && y1==y2) return NULL;

  ch=Malloc(sizeof(*ch));

  ch->type=T_CHORD;
  ch->locks=0;
  ch->x1=x1;
  ch->y1=y1;
  ch->x2=x2;
  ch->y2=y2;
  ch->z1=z1;
  ch->z2=z2;
  ch->vars=ch->varsContaining=NULL;

  ar.obj=ch;
  ActAddChord(a,&ar);

  return ch;
}

int ChangeChord3D(App a,Chord ch,double z1,double z2) {
  struct _ChangeChordRec ar;

  ar.ch=ch;
  ar.x1=ch->x1;
  ar.x2=ch->x2;
  ar.y1=ch->y1;
  ar.y2=ch->y2;
  ar.z1=z1;
  ar.z2=z2;

  ActChangeChord(a,&ar);

  return 0;
}

#define CHORD_RES 20

static void DrawChord3D(View w,Chord ch) {
  double i,x1,y1,x2,y2;

  x1=hypot(ch->x1,ch->z1);y1=ch->y1;
  for (i=1./CHORD_RES;i<1;i+=1./CHORD_RES) {
    x2=hypot(ch->x1+i*(ch->x2-ch->x1),ch->z1+i*(ch->z2-ch->z1));
    y2=ch->y1+i*(ch->y2-ch->y1);
    DrawViewLine(w,x1,y1,x2,y2);
    x1=x2;y1=y2;
  }
  x2=hypot(ch->x2,ch->z2);y2=ch->y2;
  DrawViewLine(w,x1,y1,x2,y2);
}
#endif

void DrawChord(View w,Chord ch,int mode) {
  double x,y,l;

  if (~w->showFlags & SHW_CHORDS) return;

  if (w->showFlags & SHW_NORMALS) {
    l=Point2PointDist(ch->x1,ch->y1,ch->x2,ch->y2);
    if (l>(double)w->normalLen/1e6) {
      switch(mode) {
        case DRAW_ON:
          SetViewMode(w,
            IsHighlighted(w->app,ch) ? VMX_ELEMNORMAL : VM1_ELEMNORMAL);
          break;
        case DRAW_OFF:
          if (IsHighlighted(w->app,ch)) {SetViewMode(w,VMX_ELEMNORMAL);break;}
        case DRAW_ERASE:
          SetViewMode(w,VM0_ELEMNORMAL);
          break;
      }
      x=(ch->x1+ch->x2)/2;
      y=(ch->y1+ch->y2)/2;
      DrawViewLine(w,x,y,x+(ch->y2-ch->y1)*w->normalLen/l/w->zoomX,
        y-(ch->x2-ch->x1)*w->normalLen/l/w->zoomY);
    }
  }
  if (IsMarked(w->app,ch) && !IsHighlighted(w->app,ch)) {
    switch(mode) {
      case DRAW_ON:
        SetViewMode(w,VM1_ELEMMARK);
        break;
      case DRAW_OFF:
      case DRAW_ERASE:
        SetViewMode(w,VM0_ELEMMARK);
        break;
    }
#ifdef CHORDZ /* insert the 3D drawing procedure */
    if (ch->z1!=0 || ch->z2!=0)  DrawChord3D(w,ch); else
#endif
    DrawViewLine(w,ch->x1,ch->y1,ch->x2,ch->y2);
  }
  switch(mode) {
    case DRAW_ON:
      SetViewMode(w,IsHighlighted(w->app,ch) ? VMX_CHORD : VM1_CHORD);
      break;
    case DRAW_OFF:
      if (IsHighlighted(w->app,ch)) {SetViewMode(w,VMX_CHORD);break;}
    case DRAW_ERASE:
      SetViewMode(w,VM0_CHORD);
      break;
  }
#ifdef CHORDZ /* insert the 3D drawing procedure */
  if (ch->z1!=0 || ch->z2!=0)  DrawChord3D(w,ch); else
#endif
  DrawViewLine(w,ch->x1,ch->y1,ch->x2,ch->y2);
}

#ifdef CHORDEXT /* define ExtendChord procedure */
int ExtendChord(App a,Chord ch) {
  double x,y;
  double d,d0,d1,ra,rb;
  Group g;
  void* obj;
  Elem e;
  Index ix,ixe;

  g=CreateGroup();

  for (obj=Group1st(a->mark,&ix);obj!=NULL;obj=Next(&ix))
    if (GetObjType(obj)==T_ELEM) GroupAdd(g,obj);
  if (IsEmptyGroup(g))  g=CopyGroup(a->elems,g);

  d0=Point2PointDist(ch->x1,ch->y1,ch->x2,ch->y2);

  d1=MAXDOUBLE;
  for (e=Group1st(g,&ixe);e!=NULL;e=Next(&ixe)) {
    VIntersect(ch->x1,ch->y1,ch->x2,ch->y2,
      e->n[1]->x,e->n[1]->y,e->n[2]->x,e->n[2]->y,&ra,&rb);
    if (ra<0 || rb<0 || rb>1) continue; /* the element does not intersect */
    d=Point2PointDist(ch->x1,ch->y1,ch->x1+(ch->x2-ch->x1)*ra,
      ch->y1+(ch->y2-ch->y1)*ra);
    if (d<d1) d1=d;
  }
  FreeGroup(g);

  if (d1==MAXDOUBLE) return ERR_NOELEMSINPATH;
  ChangeChord(a,ch,ch->x1,ch->y1,ch->x1+d1/d0*(ch->x2-ch->x1),
    ch->y1+d1/d0*(ch->y2-ch->y1));
  return 0;
}
#endif

static int ActAddChord(App a,ActRec ar) {
  DelRec ur;
  Chord ch;

  if (AppLocked(a)) return 0;

  ur=CreateActRec(sizeof(*ur),(ActProc)ActDelChord);
  ur->delete=ar->obj;

  ch=ar->obj;
  ar->obj=NULL;

  NotifyAdd(a,ch);
  DrawAppHighlight(a,DRAW_OFF);

  ch->vars=CreateGroup();
  ch->varsContaining=CreateGroup();
  GroupAdd(a->chords,ch);

  DrawAppObject(a,ch,DRAW_ON);

  DrawAppHighlight(a,DRAW_ON);
  NotifyAdded(a,ch);

  AddAppUpdate(a);
  AddUndoRec(a,(ActRec)ur);
  return 0;
}

static int ActDelChord(App a,DelRec ar) {
  ActRec ur;
  Chord ch;

  if (AppLocked(a)) return 0;

  ch=ar->delete;
  assert (!ch->locks);
  assert(IsEmptyGroup(ch->vars));
  assert(IsEmptyGroup(ch->varsContaining));

  ur=CreateActRec(sizeof(*ur),(ActProc)ActAddChord);
  ur->obj=ar->delete;

  NotifyDel(a,ar->delete);
  DrawAppHighlight(a,DRAW_OFF);

  DrawAppObject(a,ch,DRAW_ERASE);

  GroupDel(a->chords,ch);
  ch->varsContaining=FreeGroup(ch->varsContaining);
  ch->vars=FreeGroup(ch->vars);

  DrawAppHighlight(a,DRAW_ON);
  NotifyDeleted(a,ar->delete);

  AddAppUpdate(a);
  AddUndoRec(a,ur);
  return 0;
}

static int ActChangeChord(App a,ChangeChordRec ar) {
  ChangeChordRec ur;

  if (AppLocked(a)) return 0;

  assert(!ar->ch->locks);

  ur=CreateActRec(sizeof(*ur),(ActProc)ActChangeChord);
  ur->ch=ar->ch;

  ur->x1=ar->ch->x1;
  ur->y1=ar->ch->y1;
  ur->x2=ar->ch->x2;
  ur->y2=ar->ch->y2;
#ifdef CHORDZ /* add dummy z to UndoRec */
  ur->z1=ar->ch->z1;
  ur->z2=ar->ch->z2;
#endif

  NotifyChange(a,ar->ch);
  DrawAppHighlight(a,DRAW_OFF);

  DrawAppObject(a,ar->ch,DRAW_OFF);

  ar->ch->x1=ar->x1;
  ar->ch->y1=ar->y1;
  ar->ch->x2=ar->x2;
  ar->ch->y2=ar->y2;
#ifdef CHORDZ /* pass dummy z to new chord coordinates */
  ar->ch->z1=ar->z1;
  ar->ch->z2=ar->z2;
#endif

  DrawAppObject(a,ar->ch,DRAW_ON);

  DrawAppHighlight(a,DRAW_ON);
  NotifyChanged(a,ar->ch);

  AddAppUpdate(a);
  AddUndoRec(a,(ActRec)ur);
  return 0;
}

int ConvertElemsToChords(App a,Group elems,void** pErrObj) {
  Elem e;
  Index ix;
  Chord ch;
  double x1,y1,x2,y2;
  int i;

  if (pErrObj!=NULL) *pErrObj=NULL;

  for (e=Group1st(elems,&ix);e!=NULL;e=Next(&ix)) {
    x1=e->n[1]->x;
    y1=e->n[1]->y;
    x2=e->n[2]->x;
    y2=e->n[2]->y;
    i=IsMarked(a,e);

    if (IsLocked(e)) {
      if (pErrObj!=NULL) *pErrObj=e;
      return ERR_LOCKED;
    }

    DelElem(a,e);e=NULL;

    ch=FindChord(a,x1,y1,x2,y2);
    if (ch!=NULL) continue;
    ch=AddChord(a,x1,y1,x2,y2);
    if (ch==NULL) continue;
    if (i) MarkObject(a,ch,1);
  }

  return 0;
}

Chord FindChord(App a,double x1,double y1,double x2,double y2) {
  Chord ch;
  Index ix;

  for (ch=AppChord1st(a,&ix);ch!=NULL;ch=Next(&ix)) {
    if (ch->x1==x1 && ch->y1==y1 && ch->x2==x2 && ch->y2==y2 ||
        ch->x1==x2 && ch->y1==y2 && ch->x2==x1 && ch->y2==y1)
      return ch;
  }

  return NULL;
}

int ConvertTemplateToChords(App a) {
  XY xy,xy1;
  Index ix;

  if (a->template==NULL) return ERR_NOTEMPLATE;

  for (xy=TemplatePoint1st(a->template,&ix);xy!=NULL;xy=Next(&ix)) {
    xy1=Next(&ix);
    if (FindChord(a,xy->x,xy->y,xy1->x,xy1->y)==NULL) {
      AddChord(a,xy->x,xy->y,xy1->x,xy1->y);
    }
  }
  return 0;
}

