Main::Main(CkArgMsg* msg) {  
  int numElems = DEFAULT_NUM_ELEMS; 
  CProxy_Elem elems = CProxy_Elem::ckNew(numElems); 
  CkCallback *cb = new CkCallback( 
  CkIndex_Main::reductionCallback(NULL), thisProxy); 
  elems.ckSetReductionClient(cb); 
  elems.doWork(); 
} 

void Main::reductionCallback(CkReductionMsg *msg) { 
  int data = *((int*)(msg->getData())); 
  CkPrintf("Reduction result: %d\n", data); 
  CkExit(); 
}

void Elem::doWork() { 
  int value = thisIndex; 
  contribute(sizeof(int), &value, CkReduction::sum_int); 
}  
