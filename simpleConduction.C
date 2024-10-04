#include "fvCFD.H"

// Main program
int main(int argc, char *argv[])
{
    // Set up the time, mesh, and fields
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"

    volScalarField T
    (
        IOobject
        (
            "T",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

	const dimensionedScalar alpha ("alpha", dimensionSet(0, 2, -1, 0, 0, 0,0) , 1e-5);

    // Time-stepping loop
    while (runTime.loop())
    {

        solve
        (
           fvm::ddt(T) - fvm::laplacian(alpha,T)
        );

        // Write results for each time step
        runTime.write();
    }

    return 0;
}

//********************************** caesar wiratama ************************************ //
//************************************ pttensor.com ************************************ //
