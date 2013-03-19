#include "FiberROIProcessCLP.h"

#include <iostream>
#include <algorithm>
#include <string>

#include "itkPluginFilterWatcher.h"
#include "itkPluginUtilities.h"

#include "vtkFloatArray.h"
#include "vtkCellArray.h"
#include "vtkTransformPolyDataFilter.h"
#include "vtkSmartPointer.h"
#include "vtkPolyDataWriter.h"
#include "vtkTimerLog.h"
#include "vtkMath.h"

#include <vtkITKArchetypeImageSeriesScalarReader.h>
#include <vtkImageCast.h>

#include "vtkImageData.h"

#include "vtkPolyData.h"
#include "vtkPointData.h"
#include "vtkXMLPolyDataReader.h"
#include "vtkTransform.h"
#include "vtkXMLPolyDataWriter.h"


int main( int argc, char * argv[] )
{
  PARSE_ARGS;
  
  try
  {
  // Read in Label volume inputs

  
  // Read in fiber bundle input to be processed.
  vtkSmartPointer<vtkXMLPolyDataReader> readerPD = vtkSmartPointer<vtkXMLPolyDataReader>::New();
  readerPD->SetFileName(InputFibers.c_str());
  readerPD->Update();

  
 //3. Save the output
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetFileName(OutputFibers.c_str());
  writer->SetInput( readerPD );
  writer->Write();
  }
  catch ( ... )
      {
        std::cerr << "default exception";
        EXIT_FAILURE;
      }

  return EXIT_SUCCESS;

}
