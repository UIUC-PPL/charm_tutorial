CProxy_Master mainProxy; // readonly

/*mainchare*/
struct Master: public CBase_Master {
  int count, totalInsideCircle, totalNumTrials;
  Master(CkArgMsg* m) {
      int numTrials = atoi(m->argv[1]);
      int numChares = atoi(m->argv[2]);
      if (numTrials % numChares) { 
	  ckout << "Need numTrials to be a divisible by numChares.. Sorry" << endl;
	  CkExit();
      }	  
      for (int i = 0; i < numChares; i++)
	  CProxy_Worker::ckNew(numTrials/numChares);
      count = numChares; // wait for count responses.
      mainProxy= thisProxy;
      totalInsideCircle = 0;
      totalNumTrials = 0;
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

struct Worker : public CBase_Worker {
    float y;
    Worker( int numTrials) {
       int inTheCircle = 0;
       double x, y;
       ckout << "Hello from a simple chare running on " << CkMyPe() << endl;

       for (int i=0; i< numTrials; i++)
       { 
	   x = drand48();
	   y = drand48();
	   if ((x*x + y*y) < 1.0) 
	       inTheCircle++;
       }
       mainProxy.addContribution(inTheCircle, numTrials);
   }
};
