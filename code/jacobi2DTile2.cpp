void Tile::recvNorthGhost(float* ghostData, int dataLen) { 
  memcpy(tileData + NORTH_OFFSET, ghostData, dataLen * sizeof(float)); 
  countEvent(); 
 } 
 
 void Tile::recvSouthGhost(float* ghostData, int dataLen) { 
   memcpy(tileData + SOUTH_OFFSET, ghostData, dataLen * sizeof(float)); 
  countEvent(); 
 } 
 
 void Tile::recvWestGhost(float* ghostData, int dataLen) { 
  for (int i = 0; i < tileHeight; i++) { 
   tileData[WEST_OFFSET + (TILE_Y_STEP * i)] = ghostData[i]; 
  } 
  countEvent(); 
 } 
 
 void Tile::recvEastGhost(float* ghostData, int dataLen) { 
  for (int i = 0; i < tileHeight; i++) { 
   tileData[EAST_OFFSET + (TILE_Y_STEP * i)] = ghostData[i]; 
  } 
  countEvent(); 
 }
