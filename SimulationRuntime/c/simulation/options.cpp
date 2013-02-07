/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-2010, Linköpings University,
 * Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF THIS OSMC PUBLIC
 * LICENSE (OSMC-PL). ANY USE, REPRODUCTION OR DISTRIBUTION OF
 * THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE OF THE OSMC
 * PUBLIC LICENSE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from Linköpings University, either from the above address,
 * from the URL: http://www.ida.liu.se/projects/OpenModelica
 * and in the OpenModelica distribution.
 *
 * This program is distributed  WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS
 * OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */

#include "options.h"
#include "omc_error.h"

#include <string>

using namespace std;

const char *FLAG_NAME[FLAG_MAX] = {
  "LOG_UNKNOWN",
  
  /* FLAG_CPU */                   "cpu",
  /* FLAG_F */                     "f",
  /* FLAG_HELP */                  "help",
  /* FLAG_IIF */                   "iif",
  /* FLAG_IIM */                   "iim",
  /* FLAG_IIT */                   "iit",
  /* FLAG_INTERACTIVE */           "interactive",
  /* FLAG_IOM */                   "iom",
  /* FLAG_JAC */                   "jac",
  /* FLAG_L */                     "l",
  /* FLAG_LV */                    "lv",
  /* FLAG_MEASURETIMEPLOTFORMAT */ "measureTimePlotFormat",
  /* FLAG_NLS */                   "nls",
  /* FLAG_NOEMIT */                "noemit",
  /* FLAG_NUMJAC */                "numjac",
  /* FLAG_OUTPUT */                "output",
  /* FLAG_OVERRIDE */              "override",
  /* FLAG_OVERRIDE_FILE */         "overrideFile",
  /* FLAG_PORT */                  "port",
  /* FLAG_R */                     "r",
  /* FLAG_S */                     "s",
  /* FLAG_W */                     "w"
};

const char *FLAG_DESC[FLAG_MAX] = {
  "unknown",

  /* FLAG_CPU */                   "dumps the cpu-time into the results-file",
  /* FLAG_F */                     "value specifies a new setup XML file to the generated simulation code",
  /* FLAG_HELP */                  "get deteiled information the specifies the command-line flag",
  /* FLAG_IIF */                   "value specifies an external file for the initialization of the model",
  /* FLAG_IIM */                   "value specifies the initialization method",
  /* FLAG_IIT */                   "value specifies a time for the initialization of the model",
  /* FLAG_INTERACTIVE */           "specify interactive simulation",
  /* FLAG_IOM */                   "value specifies the initialization optimization method",
  /* FLAG_JAC */                   "specify jacobian",
  /* FLAG_L */                     "value specifies a time where the linearization of the model should be performed",
  /* FLAG_LV */                    "value specifies the logging level",
  /* FLAG_MEASURETIMEPLOTFORMAT */ "value specifies the output format of the measure time functionality",
  /* FLAG_NLS */                   "value specifies the nonlinear solver",
  /* FLAG_NOEMIT */                "do not emit any results to the result file",
  /* FLAG_NUMJAC */                "specify numerical jacobian",                                                                                                      
  /* FLAG_OUTPUT */                "output the variables a, b and c at the end of the simulation to the standard output",
  /* FLAG_OVERRIDE */              "override the variables or the simulation settings in the XML setup file",
  /* FLAG_OVERRIDE_FILE */         "will override the variables or the simulation settings in the XML setup file with the values from the file",
  /* FLAG_PORT */                  "value specifies interactive simulation port",
  /* FLAG_R */                     "value specifies a new result file than the default Model_res.mat",
  /* FLAG_S */                     "value specifies the solver",
  /* FLAG_W */                     "shows all warnings even if a related log-stream is inactive"
};

const char *FLAG_DETAILED_DESC[FLAG_MAX] = {
  "unknown",

  /* FLAG_CPU */                   "  - dumps the cpu-time into the result-file\n  - only mat-files are supported yet\n  - $cpu_time is the variable name inside the result-file",
  /* FLAG_F */                     "value specifies a new setup XML file to the generated simulation code",
  /* FLAG_HELP */                  "get deteiled information the specifies the command-line flag\n  e.g. -help=f prints detaild information for command-line flag f",
  /* FLAG_IIF */                   "value specifies an external file for the initialization of the model",
  /* FLAG_IIM */                   "value specifies the initialization method\n  none\n  numeric\n  symbolic",
  /* FLAG_IIT */                   "value specifies a time for the initialization of the model",
  /* FLAG_INTERACTIVE */           "specify interactive simulation",
  /* FLAG_IOM */                   "value specifies the initialization optimization method\n  nelder_mead_ex\n  nelder_mead_ex2\n  simplex\n  newuoa",
  /* FLAG_JAC */                   "specify jacobian",
  /* FLAG_L */                     "value specifies a time where the linearization of the model should be performed",
  /* FLAG_LV */                    "value specifies the logging level",
  /* FLAG_MEASURETIMEPLOTFORMAT */ "value specifies the output format of the measure time functionality\n  svg\n  jpg\n  ps\n  gif\n  ...",
  /* FLAG_NLS */                   "value specifies the nonlinear solver",
  /* FLAG_NOEMIT */                "do not emit any results to the result file",
  /* FLAG_NUMJAC */                "specify numerical jacobian",                                                                                                      
  /* FLAG_OUTPUT */                "output the variables a, b and c at the end of the simulation to the standard output\n  time = value, a = value, b = value, c = value",
  /* FLAG_OVERRIDE */              "override the variables or the simulation settings in the XML setup file\n  e.g. var1=start1,var2=start2,par3=start3,startTime=val1,stopTime=val2,stepSize=val3,\n       tolerance=val4,solver=\"see -s\",outputFormat=\"mat|plt|csv|empty\",variableFilter=\"filter\"",
  /* FLAG_OVERRIDE_FILE */         "will override the variables or the simulation settings in the XML setup file with the values from the file\n  note that: -overrideFile CANNOT be used with -override\n  use when variables for -override are too many and do not fit in command line size\n  overrideFileName contains lines of the form: var1=start1",
  /* FLAG_PORT */                  "value specifies interactive simulation port",
  /* FLAG_R */                     "value specifies a new result file than the default Model_res.mat",
  /* FLAG_S */                     "value specifies the solver\n  dassl\n  euler\n  rungekutta\n  inline-euler\n  inline-rungekutta\n  dasslwort\n  dasslSymJac\n  dasslNumJac\n  dasslColorSymJac\n  dasslInternalNumJac\n  qss",
  /* FLAG_W */                     "shows all warnings even if a related log-stream is inactive"
};

const int FLAG_TYPE[FLAG_MAX] = {
  FLAG_TYPE_UNKNOWN,
  
  /* FLAG_CPU */                   FLAG_TYPE_FLAG,
  /* FLAG_F */                     FLAG_TYPE_OPTION,
  /* FLAG_HELP */                  FLAG_TYPE_OPTION,
  /* FLAG_IIF */                   FLAG_TYPE_OPTION,
  /* FLAG_IIM */                   FLAG_TYPE_OPTION,
  /* FLAG_IIT */                   FLAG_TYPE_OPTION,
  /* FLAG_INTERACTIVE */           FLAG_TYPE_FLAG,
  /* FLAG_IOM */                   FLAG_TYPE_OPTION,
  /* FLAG_JAC */                   FLAG_TYPE_FLAG,
  /* FLAG_L */                     FLAG_TYPE_OPTION,
  /* FLAG_LV */                    FLAG_TYPE_OPTION,
  /* FLAG_MEASURETIMEPLOTFORMAT */ FLAG_TYPE_OPTION,
  /* FLAG_NLS */                   FLAG_TYPE_OPTION,
  /* FLAG_NOEMIT */                FLAG_TYPE_FLAG,
  /* FLAG_NUMJAC */                FLAG_TYPE_FLAG,
  /* FLAG_OUTPUT */                FLAG_TYPE_FLAG_VALUE,
  /* FLAG_OVERRIDE */              FLAG_TYPE_FLAG_VALUE,
  /* FLAG_OVERRIDE_FILE */         FLAG_TYPE_FLAG_VALUE,
  /* FLAG_PORT */                  FLAG_TYPE_OPTION,
  /* FLAG_R */                     FLAG_TYPE_OPTION,
  /* FLAG_S */                     FLAG_TYPE_OPTION,
  /* FLAG_W */                     FLAG_TYPE_FLAG
};

int checkCommandLineArguments(int argc, char **argv)
{
  for(int i=1; i<argc; ++i)
  {
    int error = 1;  /* first, suggest an error anyway */
    string tmpStr = string(argv[i]);
    
    for(int j=1; j<FLAG_MAX; ++j)
    {
      if(tmpStr == ("-" + string(FLAG_NAME[j])))
      {
        if(FLAG_TYPE[j] == FLAG_TYPE_FLAG)
          error = 0;
        else if((FLAG_TYPE[j] == FLAG_TYPE_FLAG_VALUE) && (++i < argc))
          error = 0;
      }
      else if(tmpStr.substr(0,tmpStr.find("=")) == ("-" + string(FLAG_NAME[j])))
        error = 0;
    }
    
    if(error)
    {
      WARNING1(LOG_STDOUT, "invalid command line option: %s", argv[i]);
      return 1;
    }
  }
  
  return 0;
}

int flagSet(const char *option, int argc, char** argv)
{
  for(int i=0; i<argc;i++)
  {
    if(("-"+string(option)) == string(argv[i]))
      return 1;
  }
  return 0;
}

int optionSet(const char *option, int argc, char** argv)
{
  for(int i=0; i<argc;i++)
  {
    string tmpStr=string(argv[i]);
    if(("-"+string(option)) == (tmpStr.substr(0,tmpStr.find("="))))
      return 1;
  }
  return 0;
}

/* returns the value of a flag on the form -flagname=value */
const string* getOption(const char *option, int argc, char **argv)
{
  for(int i=0; i<argc;i++)
  {
    string tmpStr=string(argv[i]);
    if(("-"+string(option)) == (tmpStr.substr(0,tmpStr.find("="))))
      return new string(tmpStr.substr(tmpStr.find("=")+1));
  }
  return NULL;
}

/* returns the value of a flag on the form -flagname value */
const string* getFlagValue(const char *option, int argc, char **argv)
{
  for(int i=0; i<argc;i++)
  {
    string tmpStr=string(argv[i]);
    if(("-"+string(option)) == string(argv[i]))
      if(argc > i+1)
        return new string(argv[i+1]);
  }
  return NULL;
}
