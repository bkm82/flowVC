/*
 *  ftle.h
 *  flowVC
 *
 *  Created by Shawn Shadden.
 *  Copyright 2010 Flow Physics Group. All rights reserved.
 *
 */


#ifndef INC_FTLE_H
#define INC_FTLE_H

#include "structs.h"

void InitializeFTLEArray(void);
void ReadInFTLELaunch(int ss);
void WriteOutFTLELaunch(int ss);
void GetFTLEForPointEarly(int ss, int i, int j, int k, double t1, double te);
void GetFTLEForPoint(int i,int j, int k, double IntTime);
LagrangianPoint Advect_FTLEPoint(int i, int j, int k, double t1, double t2);
void global_search_check(int max_loops, int count_report_interval, int *found, Search ***global_search_success);
void FTLE_dont_compute(int i, int j, int k);
void FTLE_dont_compute_neighbors(int i, int j, int k, int i_max, int j_max, int k_max);
void UpdateFTLELocations(void);
void OutputFTLE(int ss, double IntT);
void FreeFTLEData(void);
void free_global_search_success (Search ***global_search_success, int l, int m);

#endif
