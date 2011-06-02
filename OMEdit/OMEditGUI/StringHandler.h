/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Linkoping University,
 * Department of Computer and Information Science,
 * SE-58183 Linkoping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 
 * AND THIS OSMC PUBLIC LICENSE (OSMC-PL). 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S  
 * ACCEPTANCE OF THE OSMC PUBLIC LICENSE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from Linkoping University, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or  
 * http://www.openmodelica.org, and in the OpenModelica distribution. 
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS
 * OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * Main Authors 2010: Syed Adeel Asghar, Sonia Tariq
 *
 */

#ifndef STRINGHANDLER_H
#define STRINGHANDLER_H

#include <QtCore>
#include <QtGui>

class StringHandler
{
public:
    StringHandler();
    ~StringHandler();
    enum IconType {ICON, DIAGRAM, MODELICATEXT};
    enum ModelicaClasses {MODEL, CLASS, CONNECTOR, RECORD, BLOCK, FUNCTION, PACKAGE, PRIMITIVE, TYPE, PARAMETER,
                          CONSTANT, PROTECTED};
    static QString getModelicaClassType(int type);
    static QString getViewType(int type);
    static QString removeFirstLastCurlBrackets(QString value);
    static QString removeFirstLastBrackets(QString value);
    static QString removeFirstLastQuotes(QString value);
    static QString getSubStringFromDots(QString value);
    static QString removeLastDot(QString value);
    static QStringList getStrings(QString value);
    static QStringList getStrings(QString value, char start, char end);
    static QString getLastWordAfterDot(QString value);
    static QString getFirstWordBeforeDot(QString value);
    static QString removeLastSlashWord(QString value);
    static QString removeLastWordAfterDot(QString value);
    static QString removeComment(QString value);
    static QString getModifierValue(QString value);
    static QList<QString> getSimulationResultVars(QString value);
    // Returns "" if the string is not a standard Modelica string. Else it unparses it into normal form.
    static QString unparse(QString value);
    // Returns empty list if the string is not a standard Modelica string-array. Else it unparses it into normal form.
    static QStringList unparseStrings(QString value);
    // Returns false on failure
    static bool unparseBool(QString value);
    static QString getSaveFileName(QWidget* parent = 0, const QString &caption = QString(), QString * dir = 0, const QString & filter = QString(), QString * selectedFilter = 0, const QString &defaultSuffix = QString());
    static QString getOpenFileName(QWidget* parent = 0, const QString &caption = QString(), QString * dir = 0, const QString & filter = QString(), QString * selectedFilter = 0);
    static QString createTooltip(QStringList info, QString name, QString path);

protected:
    static QString mLastOpenDir;
};

#endif // STRINGHANDLER_H
