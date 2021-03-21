/**************************
 * Headers
 **************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <cmath>
#include "pdf.h"

/**************************
 * Using Declarations
 **************************/

using std::ostringstream;
using std::ifstream;
using std::complex;
using std::cout;
using std::endl;
using std::ios;

// ---------------------------------------------------
// Read 'fileName' and populate 'lines' with its
// contents (on success, return true).  On error,
// populate 'errMsg' and return false.
// ---------------------------------------------------

static bool getLines(
   const string   &fileName,
   vector<string> &lines,
   string         &errMsg
)
{
   ifstream in;

   in.open(fileName.c_str(), ios::binary);

   if(!in)
   {
      errMsg = "Could not open: [" + fileName + "]";
      return(false);
   }

   string line = "";

   for(;;)
   {
      char c = (char)in.get();

      if(in.eof())
      {
         if(line != "")
            lines.push_back(line);

         break;
      }

      line += c;

      if(c == '\n')
      {
         lines.push_back(line);
         line = "";
      }
   }

   in.close();

   return(true);
}

static void demoOne(PDF &p)
{
   p.setFont(PDF::HELVETICA_BOLD, 14);

   string s = "Facultad de Ingenieria\nMaestria en Ingenieria";


   vector<string> sv = p.wrapText(s, 150, true);

   for(int i = 0, n = sv.size(); i < n; i++)
   {
      p.showTextXY(sv[i], 230, 730 - 15 * i);
   }

   p.setFont(PDF::HELVETICA_BOLD, 10);

   s = "ACTA: ";

   p.showTextXY(s, 40, 690);

   s = "Fecha: ";

   p.rightJustifyTextXY(s, 560, 690);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "ACTA DE EVALUACION DE TRABAJO DE GRADO";
   p.showTextXY(s, 180, 660);

   p.setFont(PDF::HELVETICA, 11);

   s = "Trabajo de grado denominado: ";
   p.showTextXY(s, 40, 630);

   s = "Autor: ";
   p.showTextXY(s, 40, 600);

   s = "Periodo: ";
   p.showTextXY(s, 40, 575);

   s = "Director: ";
   p.showTextXY(s, 40, 550);

   s = "Co-Director: ";
   p.showTextXY(s, 40, 525);

   s = "Enfasis en: ";
   p.showTextXY(s, 40, 500);

   s = "Modalidad: ";
   p.showTextXY(s, 40, 475);

   s = "Jurado 1: ";
   p.showTextXY(s, 40, 450);

   s = "Jurado 2: ";
   p.showTextXY(s, 40, 425);

   s = "En atencion al desarrollo de este Trabajo de Grado y al documento y sustentacion que presento el(la) autor(a), los Jurados damos las siguientes calificaciones parciales y observaciones (los criterios a evaluar y sus ponderaciones se estipulan en el articulo 7.1 de las Directrices para Trabajo de Grado de Maestria):";
   sv = p.wrapText(s, 540, true);

   for(int i = 0, n = sv.size(); i < n; i++)
   {
      p.showTextXY(sv[i], 40, 390 - 12 * i);
   }

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "1.    Desarrollo y profundidad en el tratamiento del tema: ";
   p.showTextXY(s, 40, 330);

   p.setFont(PDF::HELVETICA, 11);

   s = "      Calificacion parcial: ";
   p.showTextXY(s, 40, 310);

   s = "Ponderacion: ";
   p.rightJustifyTextXY(s, 560, 310);

   s = "      Observaciones: ";
   p.showTextXY(s, 40, 290);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "2.    Desafio academico y cientifico del tema:";
   p.showTextXY(s, 40, 230);

   p.setFont(PDF::HELVETICA, 11);

   s = "      Calificacion parcial: ";
   p.showTextXY(s, 40, 210);

   s = "Ponderacion: ";
   p.rightJustifyTextXY(s, 560, 210);

   s = "      Observaciones: ";
   p.showTextXY(s, 40, 190);

   p.newPage();

   p.setFont(PDF::HELVETICA_BOLD, 14);

   s = "Facultad de Ingenieria\nMaestria en Ingenieria";
   sv = p.wrapText(s, 150, true);
   for(int i = 0, n = sv.size(); i < n; i++)
   {
      p.showTextXY(sv[i], 230, 730 - 15 * i);
   }

   p.setFont(PDF::HELVETICA_BOLD, 10);

   s = "ACTA: ";
   p.showTextXY(s, 40, 690);

   s = "Fecha: ";
   p.rightJustifyTextXY(s, 560, 690);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "3.    Cumplimiento de los objetivos propuestos: ";
   p.showTextXY(s, 40, 660);

   p.setFont(PDF::HELVETICA, 11);

   s = "      Calificacion parcial: ";
   p.showTextXY(s, 40, 640);

   s = "Ponderacion: ";
   p.rightJustifyTextXY(s, 560, 640);

   s = "      Observaciones: ";
   p.showTextXY(s, 40, 620);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "4.    Creatividad e innovacion de las soluciones y desarrollos propuestos:";
   p.showTextXY(s, 40, 560);

   p.setFont(PDF::HELVETICA, 11);

   s = "      Calificacion parcial: ";
   p.showTextXY(s, 40, 540);

   s = "Ponderacion: ";
   p.rightJustifyTextXY(s, 560, 540);

   s = "      Observaciones: ";
   p.showTextXY(s, 40, 520);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "5.    Validez de los resultados y conclusiones:";
   p.showTextXY(s, 40, 460);

   p.setFont(PDF::HELVETICA, 11);

   s = "      Calificacion parcial: ";
   p.showTextXY(s, 40, 440);

   s = "Ponderacion: ";
   p.rightJustifyTextXY(s, 560, 440);

   s = "      Observaciones: ";
   p.showTextXY(s, 40, 420);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "6.    Manejo y procesamiento de la informacion y bibliografia:";
   p.showTextXY(s, 40, 360);

   p.setFont(PDF::HELVETICA, 11);

   s = "      Calificacion parcial: ";
   p.showTextXY(s, 40, 340);

   s = "Ponderacion: ";
   p.rightJustifyTextXY(s, 560, 340);

   s = "      Observaciones: ";
   p.showTextXY(s, 40, 320);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "7.    Calidad y presentacion del documento escrito:";
   p.showTextXY(s, 40, 260);

   p.setFont(PDF::HELVETICA, 11);

   s = "      Calificacion parcial: ";
   p.showTextXY(s, 40, 240);

   s = "Ponderacion: ";
   p.rightJustifyTextXY(s, 560, 240);

   s = "      Observaciones: ";
   p.showTextXY(s, 40, 220);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "8.    Presentacion oral:";
   p.showTextXY(s, 40, 160);

   p.setFont(PDF::HELVETICA, 11);

   s = "      Calificacion parcial: ";
   p.showTextXY(s, 40, 140);

   s = "Ponderacion: ";
   p.rightJustifyTextXY(s, 560, 140);

   s = "      Observaciones: ";
   p.showTextXY(s, 40, 120);

   p.newPage();
   p.setFont(PDF::HELVETICA_BOLD, 14);

   s = "Facultad de Ingenieria\nMaestria en Ingenieria";
   sv = p.wrapText(s, 150, true);
   for(int i = 0, n = sv.size(); i < n; i++){
      p.showTextXY(sv[i], 230, 730 - 15 * i);
   }

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "Como resultado de estas calificaciones parciales y sus ponderaciones, la calificacion del Trabajo de";
   sv = p.wrapText(s, 540, true);
   for(int i = 0, n = sv.size(); i < n; i++){
      p.showTextXY(sv[i], 40, 670 - 12 * i);
   }

   s = "Grado es:";
   p.showTextXY(s, 40, 658);

   s = ""; //probando
   p.showTextXY(s, 110, 633);

   s = ""; //probando
   p.showTextXY(s, 310, 633);

   s = "Numeros";
   p.showTextXY(s, 95, 621);

   s = "Letras";
   p.showTextXY(s, 338, 621);

   p.setFont(PDF::HELVETICA, 11);
   s = "Observaciones adicionales: ";
   p.showTextXY(s, 40, 581);

   s = "La calificacion final quedas sujeta a que se implementen las siguientes correcciones: ";
   p.showTextXY(s, 40, 451);

   s = "________________________________     _______________________________";
   p.showTextXY(s, 80, 261);

   s = "    Firma del Jurado1                                     Firma del Jurado2";
   p.showTextXY(s, 150, 243);

   p.newPage();

   p.setFont(PDF::HELVETICA_BOLD, 14);

   s = "Facultad de Ingenieria\nMaestria en Ingenieria";
   sv = p.wrapText(s, 150, true);
   for(int i = 0, n = sv.size(); i < n; i++)
   {
      p.showTextXY(sv[i], 230, 730 - 15 * i);
   }

   p.setFont(PDF::HELVETICA_BOLD, 10);

   s = "ACTA: ";
   p.showTextXY(s, 40, 690);

   s = "Fecha: ";
   p.rightJustifyTextXY(s, 560, 690);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "RECOMENDACION DE MENCION DE HONOR AL TRABAJO DE GRADO";
   p.showTextXY(s, 120, 660);

   p.setFont(PDF::HELVETICA, 11);

   s = "Trabajo de grado denominado: ";
   p.showTextXY(s, 40, 630);

   s = "Autor: ";
   p.showTextXY(s, 40, 600);

   s = "Periodo: ";
   p.showTextXY(s, 40, 575);

   s = "Director: ";
   p.showTextXY(s, 40, 550);

   s = "Co-Director: ";
   p.showTextXY(s, 40, 525);

   s = "Enfasis en: ";
   p.showTextXY(s, 40, 500);

   s = "Modalidad: ";
   p.showTextXY(s, 40, 475);

   s = "Jurado 1: ";
   p.showTextXY(s, 40, 450);

   s = "Jurado 2: ";
   p.showTextXY(s, 40, 425);

   s = "En atencion a que el Trabajo de Grado se distingue porque la calificacion del trabajo es superior a 4,50 y se destaca por dos condiciones (que indicamos) de las siguientes tres como se estipula en el articulo 7.6 de las"; 
   sv = p.wrapText(s, 540, true);

   for(int i = 0, n = sv.size(); i < n; i++){
      p.showTextXY(sv[i], 40, 390 - 12 * i);
   }

   s = "Directrices para Trabajo de Grado de Maestria:";
   p.showTextXY(s, 40, 366);

   p.fillCircle(43, 353, 2);
   p.drawCircle(43, 353, 2);
   s = "         El estudiante supero los objetivos propuestos.";
   p.showTextXY(s, 40, 350);

   p.fillCircle(43, 335, 2);
   p.drawCircle(43, 335, 2);
   s = "         El estudiante demostro una profundidad destacable en el conocimiento y tratamiento del tema.";
   p.showTextXY(s, 40, 332);

   p.fillCircle(43, 317, 2);
   p.drawCircle(43, 317, 2);
   s = "         El tema ofrecia una dificultad superior a lo ordinario.";
   p.showTextXY(s, 40, 314);

   s = "Los jurados recomendamos que el Consejo de la Facultad otogue Mencion de Honor a este Trabajo de Grado,";
   p.showTextXY(s, 40, 294);
   s = "y motivamos esta recomendacion con base en las siguientes apreciaciones:";
   p.showTextXY(s, 40, 278);

   s = "_______________________________________________________________________________";
   p.showTextXY(s, 40, 258);

   s = "________________________________              _________________________________";
   p.showTextXY(s, 40, 218);

   s = "                         Firma del Jurado1                                       Firma del Jurado2";
   p.showTextXY(s, 40, 200);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "Decision del Consejo de la Facultad:";
   p.showTextXY(s, 40, 170);

   p.setFont(PDF::HELVETICA, 11);

   s = "En virtud de las condiciones que indicaron los Jurados y su motivacion, el Consejo de la Facultad decidio lo";
   p.showTextXY(s, 40, 150);
   
   s = "siguiente:";
   p.showTextXY(s, 40, 138);

   p.fillCircle(43, 125, 2);
   p.drawCircle(43, 125, 2);
   s = "         Conceder Mencion de Honor al Proyecto de Grado____";
   p.showTextXY(s, 40, 122);

   p.fillCircle(43, 113, 2);
   p.drawCircle(43, 113, 2);
   s = "         No Conceder Mencion de Honor al Proyecto de Grado____";
   p.showTextXY(s, 40, 110);

   s = "Tal y como se consigna en el Acta No.";
   s += "del Consejo de la Facultad.";
   p.showTextXY(s, 40, 94);
   
}

// ---------------------------------------------------
// Demonstrate:
//
//    - the use of 'drawLine' and trigonometry
//      to create a geometric line drawing
// ---------------------------------------------------

// end: demoThree

/**************************
 * Main
 **************************/

int main(){

   ostringstream out;

   out << "example-1" << ".pdf";

   string fileName = out.str();

   cout << "-----------------------------------------" << "\n";
   cout << "Creating File: [" << fileName << "]"       << "\n";
   cout << "-----------------------------------------" << "\n";

   PDF pdf;

   demoOne(pdf);

   string errMsg;

   if(!pdf.writeToFile(fileName, errMsg))
   {
      cout << errMsg << endl;
   }
   else
   {
      cout << "(File Successfully Written)" << endl;
   }

   cout << endl;

   return(0);
}
