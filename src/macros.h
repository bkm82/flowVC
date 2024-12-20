/*
 *  macros.h
 *  flowVC
 *
 *  Created by Shawn Shadden.
 *  Copyright 2010 Flow Physics Group. All rights reserved.
 *
 */

#ifndef INC_MACROS_H
#define INC_MACROS_H

/* Put all macros here */

#define LONGSTRING 200 

#define TINY 1.0e-10
#define PI 3.1415926535898
#define UNLAUNCHED 0
#define LAUNCHED 1
#define COMPLETE 2
#define CARTESIAN 0
#define UNSTRUCTURED 1
#define CELLDATA 2
#define ANALYTIC 2
#define SPATIALPERIODIC 1
#define VELOCITYPERIODIC 2

#define INITIALIZED 0
#define ASCII_LIST 1
#define VTK_POLYDATA 2
#define VTK_UNSTRUCTURED 3
#define BINARY_LIST 4

#define STAGGERED 1
#define SIGN(a, b) ((b) >= 0.0 ? fabs(a) : -fabs(a))
#define fmin(a, b) ((a) < (b) ? (a) : (b))
#define fmax(a, b) ((a) > (b) ? (a) : (b))
#define SHORTSTRING 100
#define LONGSTRING  200 

#ifdef DEBUG_LEVEL
#if DEBUG_LEVEL >= 3
#define DEBUG_3
#endif
#if DEBUG_LEVEL >= 2
#define DEBUG_2
#endif
#if DEBUG_LEVEL >= 1
#define DEBUG_1
#endif
#endif

#endif
