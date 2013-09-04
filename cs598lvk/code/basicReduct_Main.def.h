/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done(int value);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */

CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

  CProxy_Main::CProxy_Main(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      _call_Main_CkArgMsg, CMessage_CkArgMsg::__idx, __idx, 0);
  return epidx;
}


void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  new (impl_obj) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void done(int value);
 */

void CProxy_Main::done(int value, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int value
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|value;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|value;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_done_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_done_marshall2(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_done_marshall2(), impl_msg, &ckGetChareID(),0);
}

void CkIndex_Main::_call_redn_wrapper_done_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->done(value);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_done_marshall2() {
  int epidx = CkRegisterEp("done(int value)",
      _call_done_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_done_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_done_marshall2);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_done_marshall2() {
  return CkRegisterEp("redn_wrapper_done(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_done_marshall2, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_done_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->done(value);
}

int CkIndex_Main::_callmarshall_done_marshall2(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->done(value);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_done_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("value");
  implDestP|value;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void done(int value);
  idx_done_marshall2();
  idx_redn_wrapper_done_marshall2();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array Elem: ArrayElement{
Elem(CkMigrateMessage* impl_msg);
Elem(const CProxy_Main &mProxy);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Elem::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Elem(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Elem(const CProxy_Main &mProxy);
 */

void CProxyElement_Elem::insert(const CProxy_Main &mProxy, int onPE, const CkEntryOptions *impl_e_opts)
{ 
  //Marshall: const CProxy_Main &mProxy
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)mProxy;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)mProxy;
  }
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Elem::idx_Elem_marshall1(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Elem(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_Elem::reg_Elem_CkMigrateMessage() {
  int epidx = CkRegisterEp("Elem(CkMigrateMessage* impl_msg)",
      _call_Elem_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}


void CkIndex_Elem::_call_Elem_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  Elem* impl_obj = static_cast<Elem *>(impl_obj_void);
  new (impl_obj) Elem((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Elem(const CProxy_Main &mProxy);
 */

CkArrayID CProxy_Elem::ckNew(const CProxy_Main &mProxy, const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{ 
  //Marshall: const CProxy_Main &mProxy
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)mProxy;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)mProxy;
  }
   return ckCreateArray((CkArrayMessage *)impl_msg,CkIndex_Elem::idx_Elem_marshall1(),opts);
}

CkArrayID CProxy_Elem::ckNew(const CProxy_Main &mProxy, const int s1, const CkEntryOptions *impl_e_opts)
{ 
  //Marshall: const CProxy_Main &mProxy
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)mProxy;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)mProxy;
  }
   return ckCreateArray((CkArrayMessage *)impl_msg,CkIndex_Elem::idx_Elem_marshall1(),CkArrayOptions(s1));
}

// Entry point registration function

int CkIndex_Elem::reg_Elem_marshall1() {
  int epidx = CkRegisterEp("Elem(const CProxy_Main &mProxy)",
      _call_Elem_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Elem_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Elem_marshall1);

  return epidx;
}


void CkIndex_Elem::_call_Elem_marshall1(void* impl_msg, void* impl_obj_void)
{
  Elem* impl_obj = static_cast<Elem *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CProxy_Main &mProxy*/
  PUP::fromMem implP(impl_buf);
  CProxy_Main mProxy; implP|mProxy;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Elem(mProxy);
}

int CkIndex_Elem::_callmarshall_Elem_marshall1(char* impl_buf, void* impl_obj_void) {
  Elem* impl_obj = static_cast< Elem *>(impl_obj_void);
  /*Unmarshall pup'd fields: const CProxy_Main &mProxy*/
  PUP::fromMem implP(impl_buf);
  CProxy_Main mProxy; implP|mProxy;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Elem(mProxy);
  return implP.size();
}

void CkIndex_Elem::_marshallmessagepup_Elem_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CProxy_Main &mProxy*/
  PUP::fromMem implP(impl_buf);
  CProxy_Main mProxy; implP|mProxy;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("mProxy");
  implDestP|mProxy;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Elem(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Elem(const CProxy_Main &mProxy);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Elem::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Elem(CkMigrateMessage* impl_msg);
  idx_Elem_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Elem_CkMigrateMessage());

  // REG: Elem(const CProxy_Main &mProxy);
  idx_Elem_marshall1();

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerbasicReduct_Main(void)
{
  static int _done = 0; if(_done) return; _done = 1;
/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done(int value);
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array Elem: ArrayElement{
Elem(CkMigrateMessage* impl_msg);
Elem(const CProxy_Main &mProxy);
};
*/
  CkIndex_Elem::__register("Elem", sizeof(Elem));

}
extern "C" void CkRegisterMainModule(void) {
  _registerbasicReduct_Main();
}
#endif /* CK_TEMPLATES_ONLY */
