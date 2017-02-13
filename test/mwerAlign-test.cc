/*--------------------------------------------------------------
 Copyright 2006 (c) by RWTH Aachen - Lehrstuhl fuer Informatik 6
 Richard Zens, Evgeny Matusov, Gregor Leusch
 ---------------------------------------------------------------

This header file is part of the MwerAlign C++ Library.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
USA.
*/
#include <string>
#include "mwerAlign.hh"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;



int main(int argc,char**argv) {

  string hypfile="I will now try to segment this corpus I know how to do it I do\n";
  string reffile="I will try to align this corpus # I shall try to align that data\n I know how this is done # I realize how to do it\n yes I can # yes I do\n";


    // le constructeur de ifstream permet d'ouvrir un fichier en lecture
    ifstream fichier( "example/hyp.txt" );

    if ( fichier ) // ce test échoue si le fichier n'est pas ouvert
    {
        std::string ligne; // variable contenant chaque ligne lue
hypfile="";
        // cette boucle s'arrête dès qu'une erreur de lecture survient
        while ( std::getline( fichier, ligne ) )
        { hypfile =hypfile+ligne+"\n";
        }
    }
//~ std::cout << hypfile << std::endl;
 
    // le constructeur de ifstream permet d'ouvrir un fichier en lecture
     ifstream fichierRef( "example/ref.txt" );

    if ( fichierRef ) // ce test échoue si le fichier n'est pas ouvert
    {
        std::string ligne; // variable contenant chaque ligne lue
reffile="";
        // cette boucle s'arrête dès qu'une erreur de lecture survient
        while ( std::getline( fichierRef, ligne ) )
        { reffile =reffile+ligne+"\n";
        }
    }
    //~ std::cout << reffile << std::endl;
  
  double maxER=-1.0;
  bool human=false;
  MwerSegmenter ms(maxER, human);
  string result;
  ms.mwerAlign(reffile, hypfile, result);
  std::cout << result << "\n";
}
