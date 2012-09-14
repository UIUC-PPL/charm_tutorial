void Main::reductionCallback(CkReductionMsg* msg) { 
 // Get the result of the reduction 
 float maxStepDiff = *((float*)(msg->getData())); 
 delete msg; // Don’t need the message any more 
 
 // Display this step’s maximum difference to the user 
 static int numStepsCompleted = 0; 
 CkPrintf("Step %d: %f\n", ++numStepsCompleted, maxStepDiff); 
 
 // Check to see if the difference is small enough that the 
 // application can complete 
 if (maxStepDiff <= targetDiff) { 
   CkExit(); // Program finished 
 } else { 
   grid.startStep(); // Another step needs to be run 
} 
