void Tile::doCalc() { 
 register float maxDiff = ((float)(0.0)); 
 
 for (int y = 1; y < tileHeight + 1; y++) 
   for (int x = (y == 1 ? 2 : 1); x < tileWidth + 1; x++) { 
     float origVal = tileData[XY_TO_I(x,y)]; 
     float newVal = (origVal + tileData[XY_TO_I(x+1, y)] + 
      tileData[XY_TO_I(x-1, y)] + tileData[XY_TO_I(x, y+1)] 
      + tileData[XY_TO_I(x, y-1)]) * ((float)(0.2)); 
     scratchData[XY_TO_I(x,y)] = newVal; 
     float diff = fabsf(origVal - newVal); 
     maxDiff = fmax(maxDiff, diff); 
   } 
 
 contribute(sizeof(float), &maxDiff, CkReduction::max_float); 
 
 register float* tmp = tileData; 
 tileData = scratchData; 
 scratchData = tmp; 
 enforceConstants(); 
} 
