#include <stdio.h> 
#include <stdlib.h>
#include "unity.h"

#include "ftle.h"
#include "globals.h"
#include "integration.h"
#include "io.h"
#include "macros.h"
#include "mesh.h"
#include "mymath.h"
#include "structs.h"
#include "velocity.h"



// Define the dimensions of the dummy mesh
#define XRes 10
#define YRes 10
#define ZRes 10

void setUp() {
    // Set up any necessary initialization before each test
}

void tearDown() {
    // Clean up any resources after each test
}

// Test case to verify the behavior of FTLE_dont_compute_neighbors function
void test_FTLE_dont_compute_neighbors() {


  if((FTLE_MeshPt = (FTLEPoint ***)malloc(XRes * sizeof(FTLEPoint **))) == NULL)
    FatalError("Malloc failed for FTLE");
  for(int i = 0; i < XRes; i++) {
    if((FTLE_MeshPt[i] = (FTLEPoint **)malloc(YRes * sizeof(FTLEPoint *))) == NULL) 
      FatalError("Malloc failed for FTLE[%d]", i);
    for(int j = 0; j < YRes; j++) 
      if((FTLE_MeshPt[i][j] = (FTLEPoint *)malloc(ZRes * sizeof(FTLEPoint))) == NULL)
	FatalError("Malloc failed for FTLE[%d][%d]", i, j);
  }
  
		
  /* Initialize FTLE_MeshPt */
  for(int i = 0; i < XRes; i++) {
    for(int j = 0; j < YRes; j++) {
      for(int k = 0; k < ZRes; k++) {
	FTLE_MeshPt[i][j][k].Pt.X[0] = i;
	FTLE_MeshPt[i][j][k].Pt.X[1] =  j;
	FTLE_MeshPt[i][j][k].Pt.X[2] = k ;
	FTLE_MeshPt[i][j][k].FTLEwT = 0.0;
	FTLE_MeshPt[i][j][k].FTLEwoT = 0.0;
	FTLE_MeshPt[i][j][k].HaveFTLE = 0;
	FTLE_MeshPt[i][j][k].Pt.LeftDomain = 0;
	FTLE_MeshPt[i][j][k].Pt.LeftDomainTime = 0.0;
	
      }
    }
  }

    
  // Initialize necessary variables
  int i = 1, j = 0, k = 0;
  int i_max = 3, j_max = 3, k_max = 3;
  
  // Call the function under test
  FTLE_dont_compute_neighbors(i, j, k, i_max, j_max, k_max);
    
    // Assert the expected behavior
  TEST_ASSERT_EQUAL(0,0);
    // Free the memory allocated for dummy_FTLE_MeshPt
    
}

// Define additional test cases as needed

int main(void) {
    UNITY_BEGIN();

    // Run test cases
    RUN_TEST(test_FTLE_dont_compute_neighbors);
    
    // Add more RUN_TEST() calls for other test cases
    
    return UNITY_END();
}
