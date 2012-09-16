// 2D jacobi iterations
do {
    // Exchange boundary (ghost layer) values
    MPI_Sendrecv(); // north neighbor
    MPI_Sendrecv(); // east neighbor
    MPI_Sendrecv(); // south neighbor
    MPI_Sendrecv(); // west neighbor

    // Update internal and boundary values
    compute_kernel();

    // Check convergence
    compute_local_err();
    MPI_Allreduce();
} while (not converged);

