/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkDirectory.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
/**
 * itkDirectory provides a portable way of finding the names of the files
 * in a system directory.
 *
 * itkDirectory works with windows and unix only.
 */

#ifndef __itkDirectory_h
#define __itkDirectory_h

#include "itkObject.h"
#include <string>
#include <vector>

class ITK_EXPORT itkDirectory : public itkObject
{
public:
  /**
   * Create a new itkDirectory object.
   */
  static itkDirectory *New() 
    {return new itkDirectory;};

  /**
   * Return the class name as a string.
   */
  itkTypeMacro(itkDirectory,itkObject);

  /**
   * Load the specified directory and load the names of the files
   * in that directory. 0 is returned if the directory can not be 
   * opened, 1 if it is opened.   
   */
  bool Load(const char* dir);

  /**
   * Return the number of files in the current directory.
   */
  int GetNumberOfFiles() { return m_Files.size();}

  /**
   * Return the file at the given index, the indexing is 0 based
   */
  const char* GetFile(unsigned int index);

protected:
  itkDirectory();
  ~itkDirectory() ;
  itkDirectory(const itkDirectory&) {};
  void operator=(const itkDirectory&) {};
  virtual void PrintSelf(std::ostream& os, itkIndent indent);

private:
  std::vector<std::string> m_Files; // Array of Files
  std::string m_Path;               // Path to Open'ed directory
};

#endif
