/******************************************************************************
 *
 * File: ex3.c
 *
 * System: C Programming Advanced, Exercise 3
 * 
 * Description: This program tests the PERIODIC_parse_periodic_rec function.
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 19-Oct-2000  Charles Fordyce     1.0
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <periodic.h>

/***************************************************************************
 * constants
 ***************************************************************************/

/***************************************************************************
 * typedefs
 ***************************************************************************/

/***************************************************************************
 * prototypes
 ***************************************************************************/

/***************************************************************************
 * main function
 ***************************************************************************/
int main( void )
{
  int inx = 0;
  PERIODIC_data_t periodic_rec;
  char * periodic_str[] = {     
    "89   227.0278    Ac         Actinium",
    "47     107.87    Ag           Silver",
    "13    26.9815    Al         Aluminum",
    "95   243.0614    Am        Americium",
    "18     39.948    Ar            Argon",
    "33     74.992    As          Arsenic",
    "85    209.987    At         Astatine",
    "79    196.967    Au             Gold",
    "5     10.811     B            Boron",
    "56     137.34    Ba           Barium",
    "4     9.0122    Be        Beryllium",
    "83     208.98    Bi          Bismuth",
    "97   247.0703    Bk        Berkelium",
    "35     79.909    Br          Bromine",
    "6    12.0112     C           Carbon",
    "20      40.08    Ca          Calcium",
    "48      112.4    Cd          Cadmium",
    "58     140.12    Ce           Cerium",
    "98   251.0796    Cf      Californium",
    "17     35.453    Cl         Chlorine",
    "96   247.0704    Cm           Curium",
    "27     58.933    Co           Cobalt",
    "24     51.996    Cr         Chromium",
    "55    132.905    Cs           Cesium",
    "29      63.54    Cu           Copper",
    "66      162.5    Dy       Dysprosium",
    "68     167.26    Er           Erbium",
    "99   254.0881    Es      Einsteinium",
    "63     151.96    Eu         Europium",
    "9    18.9984     F         Fluorine",
    "26     55.847    Fe             Iron",
    "100   257.0951    Fm          Fermium",
    "87   223.0189    Fr         Francium",
    "31      69.72    Ga          Gallium",
    "64     157.25    Gd       Gadolinium",
    "32      72.59    Ge        Germanium",
    "1    1.00797     H         Hydrogen",
    "2     4.0026    He           Helium",
    "72     178.49    Hf          Hafnium",
    "80     200.59    Hg          Mercury",
    "67     164.93    Ho          Holmium",
    "53    126.904     I           Iodine",
    "49     114.82    In           Indium",
    "77     192.22    Ir          Iridium",
    "19     39.102     K        Potassium",
    "36       83.8    Kr          Krypton",
    "57     138.91    La        Lanthanum",
    "3      6.939    Li          Lithium",
    "103   256.0986    Lr       Lawrencium",
    "71     174.97    Lu         Lutetium",
    "101   257.0956    Md      Mendelevium",
    "12     24.312    Mg        Magnesium",
    "25     54.938    Mn        Manganese",
    "42      95.94    Mo       Molybdenum",
    "7    14.0067     N         Nitrogen",
    "11    22.9898    Na           Sodium",
    "41     92.906    Nb          Niobium",
    "60     144.24    Nd        Neodymium",
    "10     20.183    Ne             Neon",
    "28      58.71    Ni           Nickel",
    "102   255.0933    No         Nobelium",
    "93        237    Np        Neptunium",
    "8    15.9994     O           Oxygen",
    "76      190.2    Os           Osmium",
    "15     30.984     P       Phosphorus",
    "91   231.0359    Pa     Protactinium",
    "82     207.19    Pb             Lead",
    "46      106.4    Pd        Palladium",
    "61   144.9128    Pm       Promethium",
    "84     208.98    Po         Polonium",
    "59    140.907    Pr     Praseodymium",
    "78     195.09    Pt         Platinum",
    "94        242    Pu        Plutonium",
    "88        226    Ra           Radium",
    "37      85.47    Rb         Rubidium",
    "75      186.2    Re          Rhenium",
    "45    102.905    Rh          Rhodium",
    "86   222.0176    Rn            Radon",
    "44     101.07    Ru        Ruthenium",
    "16     32.064     S           Sulfur",
    "51     121.75    Sb         Antimony",
    "21     44.956    Sc         Scandium",
    "34      78.96    Se         Selenium",
    "14     28.086    Si          Silicon",
    "62     150.35    Sm         Samarium",
    "50     118.69    Sn              Tin",
    "38      87.62    Sr        Strontium",
    "73    180.948    Ta         Tantalum",
    "65    158.924    Tb          Terbium",
    "43    96.9062    Tc       Technetium",
    "52     127.60    Te        Tellurium",
    "90    232.038    Th          Thorium",
    "22       47.9    Ti         Titanium",
    "81     204.37    Tl         Thallium",
    "69    168.934    Tm          Thulium",
    "92     238.03     U          Uranium",
    "23     50.942     V         Vanadium",
    "74     183.85     W          Wolfram",
    "54      131.3    Xe            Xenon",
    "39    88.9059     Y          Yttrium",
    "70     173.04    Yb        Ytterbium",
    "30      65.37    Zn             Zinc",
    "40      91.22    Zr        Zirconium"
  };
    
    for (; inx < sizeof(periodic_str)/sizeof(char *); inx++)
      {
	memset(&periodic_rec, 0, sizeof(periodic_rec));
	
	if ( PERIODIC_parse_periodic_rec(periodic_str[inx], &periodic_rec ) )
	  {
	    printf( "Parsed this string: %s\n", periodic_str[inx] );
	    PERIODIC_print_recs( &periodic_rec, 1 );
	  }
	else
	  {
	    fprintf( stderr, "Failed to parse >>%s<<\n", periodic_str[inx] );
	  }
      }
}

