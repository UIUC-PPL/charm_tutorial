// 2D jacobi iterations
do {
    // Exchange boundary (ghost layer) values
    MPI_Irecv();    MPI_Isend(); // north neighbor
    MPI_Irecv();    MPI_Isend(); // east neighbor
    MPI_Irecv();    MPI_Isend(); // south neighbor
    MPI_Irecv();    MPI_Isend(); // west neighbor

    // Update internal values
    compute_internal();

    // Wait on boundary exchange
    MPI_Waitall();
    // Update boundary values
    compute_boundary();

    // Check convergence
    compute_local_err();
    MPI_Allreduce();
} while (not converged);
