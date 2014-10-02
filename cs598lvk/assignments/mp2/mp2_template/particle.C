#include <stdlib.h>
#include <vector>
#include "pup_stl.h"
#include "Particle.h"
#include "ParticleExercise.decl.h"

#define ITERATION (100)

/*readonly*/ CProxy_Main mainProxy;
/*readonly*/ CProxy_Cell cellProxy;
/*readonly*/ int particlesPerCell;
/*readonly*/ int cellDimension;

using namespace std;

class Main: public CBase_Main {

  public:
    int doneCells;
    Main(CkArgMsg* m) {
      doneCells = 0;
      if(m->argc < 3) CkAbort("USAGE: ./charmrun +p<number_of_processors> ./particle <number of particles per cell> <size of array>");

      mainProxy = thisProxy;
      particlesPerCell = atoi(m->argv[1]);
      cellDimension = atoi(m->argv[2]);
      delete m;

      //TODO: Create the grid and start the simulation by calling run()
    }

    // TODO: Add entry methods which will be a target of the reduction for avg
    // and max counts and exiting when the iterations are done

    void printTotal(int total, int max, int iter){
        CkPrintf("ITER %d, MAX: %d, TOTAL: %d\n", iter, max, total);
    }
};

// This class represent the cells of the simulation.
/// Each cell contains a vector of particle.
// On each time step, the cell perturbs the particles and moves them to neighboring cells as necessary.
class Cell: public CBase_Cell {
  Cell_SDAG_CODE

  public:
    int iteration;
    vector<Particle> particles;
    //TODO: more variables might be needed

    Cell() {
      __sdag_init();
      iteration = 0;
      populateCell(particlesPerCell); //creates random particles within the cell

    }
    Cell(CkMigrateMessage* m) {}

    void pup(PUP::er &p){
      CBase_Cell::pup(p);
      __sdag_pup(p);
      p|iteration;
      p|particles;
      //TODO: if you added more variable, decide if they need to go into the
      //pup method
    }

    void updateParticles() {
        //TODO:move the particles

        //TODO:use perturb function for the location of new particles
    }

    //you can add more methods if you want or need to

  private:

    void populateCell(int initialElements) {
      //create random particles and add then to the particles vector
    }

    //change the location of the particle within the range of 8 neighbours
    //the location of the particles might exceed the bounds of the chare array
    //as a result of this functions, so you need to handle that case when deciding 
    //which particle to go which neighbour chare
    //e.g. the right neighbour of chare indexed[k-1,0] is chare [0,0]
    void perturb(Particle* particle) {
      //drand48 creates a random number between [0-1]	
      double deltax = (drand48()-drand48())*10;
      double deltay = (drand48()-drand48())*10;

      particle->x += deltax;
      particle->y += deltay;
    }


};

#include "ParticleExercise.def.h"
