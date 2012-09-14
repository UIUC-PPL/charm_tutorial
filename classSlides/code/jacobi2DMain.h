class Main : public CBase_Main { 
 private: 
 CProxy_Tile grid; 
 void processCommandLine(const CkArgMsg * const msg); 
 void displayUsage(const CkArgMsg * const msg); 
 void displayHeader(); 
 
 public: 
 Main(CkMigrateMessage* msg); 
 Main(CkArgMsg* msg); 
 void reductionCallback(CkReductionMsg* msg); 
}; 
