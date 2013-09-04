Main::Main(CkArgMsg* msg) { 
 processCommandLine(msg); 
 displayHeader(); 
 delete msg; 
 
 // Create the grid tiles and set the reduction client 
 grid = CProxy_Tile::ckNew(gridWidth, gridHeight); 
 CkCallback* cb = new CkCallback( 
 CkIndex_Main::reductionCallback(NULL), thisProxy); 
 grid.ckSetReductionClient(cb); 
 
 // Start the first step 
 grid.startStep(); 
} 
