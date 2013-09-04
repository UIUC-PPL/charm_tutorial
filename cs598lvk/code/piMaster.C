CProxy_Master mainProxy; // readonly

struct Master: public CBase_Master {
  int count, totalInsideCircle, totalNumTrials;
  Master(CkArgMsg* m) {
    int numTrials = atoi(m->argv[1]), numChares = atoi(m->argv[2]);
    if (numTrials % numChares) { 
      ckout << "Need numTrials to be a divisible by numChares.. Sorry" << endl;
      CkExit();
    }	  
    for (int i = 0; i < numChares; i++)
      CProxy_Worker::ckNew(numTrials/numChares);
    count = numChares; // wait for count responses.
    mainProxy= thisProxy;
    totalInsideCircle = totalNumTrials = 0;
  };

  void addContribution(int numIn, int numTrials) {
    totalInsideCircle += numIn;
    totalNumTrials += numTrials;
    count--;
    if (count == 0) {
      double myPi = 4.0* ((double) (totalInsideCircle))
        / ((double) (totalNumTrials));
      ckout << "Approximated value of pi is:" << myPi << endl;
      CkExit();
    }
  }
};
