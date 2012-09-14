void Tile::countEvent() { 
 if ((++eventCounter) >= 5) { 
  eventCounter = 0; 
  doCalc(); 
 } 
} 
