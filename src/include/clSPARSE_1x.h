#pragma once
#ifndef _CL_SPARSE_1x_H_
#define _CL_SPARSE_1x_H_

#if defined(__APPLE__) || defined(__MACOSX)
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

// Data types used to pass OpenCL objects into the clSPARSE library
// These are plain PoD containers; no methods defined
// Users are responsible for creating and destroying the OpenCL objects
// Helper functions may be provided to assist users in creating and 
// destroying these objects
typedef struct clsparseScalar_
{
    // OpenCL state
    cl_mem value;

    //OpenCL meta
    cl_ulong offValue;
} clsparseScalar;

typedef struct clsparseVector_
{
    // Matrix meta
    cl_int n;

    // OpenCL state
    cl_mem values;

    //OpenCL meta
    cl_ulong offValues;
} clsparseVector;

typedef struct clsparseCsrMatrix_
{
    // Matrix meta
    cl_int m;
    cl_int n;
    cl_int nnz;

    // OpenCL state
    cl_mem values;
    cl_mem colIndices;
    cl_mem rowOffsets;
    cl_mem rowBlocks;      // It is possible that this pointer may be NULL

    //OpenCL meta
    cl_ulong offValues;
    cl_ulong offColInd;
    cl_ulong offRowOff;
    cl_ulong offRowBlocks;
    size_t rowBlockSize;
} clsparseCsrMatrix;

typedef struct clsparseCooMatrix_
{
    // Matrix meta
    cl_int m;
    cl_int n;
    cl_int nnz;

    // OpenCL state
    cl_mem values;
    cl_mem colIndices;
    cl_mem rowIndices;

    //OpenCL meta
    cl_ulong offValues;
    cl_ulong offColInd;
    cl_ulong offRowInd;
} clsparseCooMatrix;

//for sake of clarity in the interface
typedef struct clsparseDenseMatrix_
{
    cl_int m;
    cl_int n;

    cl_mem values;
} clsparseDenseMatrix;

#endif