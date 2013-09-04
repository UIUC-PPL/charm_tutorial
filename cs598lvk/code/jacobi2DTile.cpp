Tile::startStep() { 
 register const int thisX = thisIndex.x, thisY = thisIndex.y; 
 
 float* northGhost = tileData + NORTH_OFFSET + TILE_Y_STEP; 
 thisProxy(thisX, thisY > 0 ? thisY - 1 : gridHeight - 1) 
 .recvSouthGhost(northGhost, tileWidth); 
 
 float* southData = tileData + SOUTH_OFFSET - TILE_Y_STEP; 
 thisProxy(thisX, thisY < gridHeight - 1 ? thisY + 1 : 0) 
 .recvNorthGhost(southData, tileWidth); 
 
 for (int i = 0; i < tileHeight; i++) 
 scratchData[i] = tileData[WEST_OFFSET + TILE_X_STEP + (TILE_Y_STEP * i)]; 
 thisProxy(thisX > 0 ? thisX - 1 : gridWidth - 1, thisY) 
 .recvEastGhost(scratchData, tileHeight); 
 
 for (int i = 0; i < tileHeight; i++) 
 scratchData[i] = tileData[EAST_OFFSET - TILE_X_STEP + (TILE_Y_STEP * i)]; 
 thisProxy(thisX < gridWidth - 1 ? thisX + 1 : 0, thisY) 
 .recvWestGhost(scratchData, tileHeight); 
 
 countEvent(); 
}
