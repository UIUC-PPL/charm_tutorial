struct Worker : public CBase_Worker {
  float y;
  Worker( int numTrials) {
    int inTheCircle = 0;
    double x, y;
    ckout << "Hello from a simple chare running on " << CkMyPe() << endl;

    for (int i=0; i< numTrials; i++) { 
      x = drand48();
      y = drand48();
      if ((x*x + y*y) < 1.0) 
        inTheCircle++;
    }
    mainProxy.addContribution(inTheCircle, numTrials);
  }
};
