#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
#include <math.h>
using std::cout;
using std::endl;
using std::string;
using std::hex;
using std::stringstream;
using std::ios_base;
using namespace std;



int main()
{

	ifstream mysic("3.txt");

	string text1;
	string text2;
	string text3;

    int n=0,m,qi;

    int i=0,f[999],d=1,bin[99999];
    string x[999],y[999],z[999],a,b[999],c[999],h[999],a1[999],a2[999],a3[999];

    while (mysic >> text1 >> text2 >>text3) {
        char hex_num[20];
        x[i]=text1;
        y[i]=text2;
        z[i]=text3;
        if(x[i]=="--"&&y[i]=="--"&&z[i]=="--"){
            n=4150;
        }
        if(x[i]=="BUFFER"&&y[i]=="RESB"&&z[i]=="4096"){
            f[i]-=n;
            n=0;
        }
        if(x[i]=="RDREC"){
            f[i]=n-1;
            n-=1;
        }
        if(x[i]=="--"&&y[i]=="CLEAR"&&z[i]=="S"){
            f[i]=n-1;
            n-=1;
        }
        if(x[i]=="--"&&y[i]=="CLEAR"&&z[i]=="A"){
            f[i]=n-1;
            n-=1;
        }
        if(x[i]=="--"&&y[i]=="COMPR"&&z[i]=="A,S"){
            f[i]=n-1;
            n-=1;
        }
        if(x[i]=="--"&&y[i]=="TIXR"&&z[i]=="T"){
            f[i]=n-1;
            n-=1;
        }
        if(x[i]=="INPUT"&&y[i]=="BYTE"&&z[i]=="X'F1'"){
            f[i]=n-2;
            n-=2;
        }
        if(x[i]=="WRREC"&&y[i]=="CLEAR"&&z[i]=="X"){
            f[i]=n-1;
            n-=1;
        }




        if(y[i]=="STL" || y[i]=="+STL"){
            h[i]="000101";
        }
        if(y[i]=="LDB"||y[i]=="+LDB"){
            h[i]="011010";
        }
        if(y[i]=="JSUB" || y[i]=="+JSUB"){
            h[i]="010010";
        }
        if(y[i]=="LDA"||y[i]=="+LDA"){
            h[i]="000000";
        }
        if(y[i]=="COMP"||y[i]=="+COMP"){
            h[i]="001010";
        }
        if(y[i]=="JEQ"||y[i]=="+JEQ"){
            h[i]="001100";
        }
        if(y[i]=="J"||y[i]=="+J"){
            h[i]="001111";
        }
        if(y[i]=="STA"||y[i]=="+STA"){
            h[i]="000011";
        }
        if(y[i]=="LDT"||y[i]=="+LDT"){
            h[i]="011101";
        }
        if(y[i]=="TD"||y[i]=="+TD"){
            h[i]="111000";
        }
        if(y[i]=="STA"||y[i]=="+STA"){
            h[i]="000011";
        }
        if(y[i]=="RD"||y[i]=="+RD"){
            h[i]="110110";
        }
        if(y[i]=="COMPR"){
            h[i]="A0";
            if(z[i]=="A,S"){
                h[i]+="04";
            }
        }
        if(y[i]=="STCH"||y[i]=="+STCH"){
            h[i]="010101";
        }
        if(y[i]=="TIXR"){
            h[i]="B8";
            if(z[i]=="T"){
                h[i]+="5";
            }
        }
        if(y[i]=="JLT"||y[i]=="+JLT"){
            h[i]="001110";
        }
        if(y[i]=="STX"||y[i]=="+STX"){
            h[i]="000100";
        }
        if(y[i]=="RSUB"||y[i]=="+RSUB"){
            h[i]="010011";
        }
        if(y[i]=="LDCH"||y[i]=="+LDCH"){
            h[i]="010100";
        }
        if(y[i]=="WD"||y[i]=="+WD"){
            h[i]="110111";
        }
        if(y[i]=="CLEAR"){
            h[i]="B4";
            if(z[i]=="X"){
                h[i]+="1";
            }
            else if(z[i]=="A"){
                h[i]+="0";
            }
            else if(z[i]=="S"){
                h[i]+="4";
            }
        }
        if(y[i]=="BYTE" && z[i]=="X'f1'"){
            h[i]="F1";
        }
        if(y[i]=="BYTE" && z[i]=="X'05'"){
            h[i]="05";
        }
        if(y[i]=="BYTE" && z[i]=="C'EOF'"){
            h[i]="454F46";
        }




        if(y[i]=="RESW"||y[i]=="RESB"|| y[i]=="--" ||y[i]=="START"){
            h[i]+="--";
        }
        else if(y[i]=="CLEAR"||y[i]=="COMPR"|| y[i]=="--" ||y[i]=="TIXR"||y[i]=="BYTE"){
            h[i]+="";
        }
        ///n i
        else{
            if(z[i][0]!='#' && z[i][0]!='@'){
                h[i]+="11";
            }
            if(z[i][0]=='@'){
                h[i]+="10";
            }
            if(z[i][0]=='#'){
                h[i]+="01";
            }

           ///x
            int p=z[i].size();
            if(z[i][p-1]=='X' && z[i][p-2]==','){
                h[i]+="1";
            }
            else{
                h[i]+="0";
            }
            //bp
            if(z[i]=="#0"||z[i]=="#3"|z[i]=="#4096"){
                h[i]+="00";
            }
            else
                h[i]+="01";

            //e
            if(y[i][0]=='+'){
                h[i]+="1";
            }
            else{
                h[i]+="0";
            }
        }


        if(y[i]=="CLEAR"||y[i]=="TIXR"){
            h[i]+="0";
        }
        if(z[i]=="RETADR"){
            h[i]+="02D";
        }
        if(z[i]=="@RETADR"){
            h[i]+="003";
        }
        if(z[i]=="#LENGTH"){
            h[i]+="02D";
        }
        if(z[i]=="RDREC"){
            h[i]+="01036";
        }
        if(z[i]=="LENGTH"){
            h[i]+="02D";
        }
        if(z[i]=="#0"){
            h[i]+="000";
        }
        if(z[i]=="#3"){
            h[i]+="003";
        }
        if(z[i]=="#4096"){
            h[i]+="01000";
        }
        if(z[i]=="ENDFIL"){
            h[i]+="007";
        }
        if(z[i]=="WRREC"){
            h[i]+="0105D";
        }
        if(z[i]=="CLOOP"){
            h[i]+="FEC";
        }
        if(z[i]=="EOF"){
            h[i]+="010";
        }
        if(z[i]=="BUFFER"){
            h[i]+="016";
        }
        if(z[i]=="INPUT"){
            h[i]+="019";
        }
        if(z[i]=="RLOOP"){
            h[i]+="FFA";
        }
        if(z[i]=="EXIT"){
            h[i]+="008";
        }










        if((y[i][0]=='+')){
            f[i]=n+1;
            n+=1;
        }
        else if((y[i][0]=='+')){
            f[i]=n+1;
            n+=1;
        }
        else if((y[i][0]=='+')){
            f[i]=n+1;
            n+=1;
        }
        else{
            f[i]=n;
        }








        m=f[i];
        i++;
        sprintf(hex_num,"%X",m);
        a=hex_num;
        c[i]=a;
        n+=3;

    }
	mysic.close();


	for(int j=0;j<i;j++){
        if(z[j]=="BUFFER,X"){
            if(c[j].size()<1){
                cout<<"0000"<<c[j]<<"\t"<<x[j]<<"\t"<<y[j]<<"\t"<<z[j]<<" "<<h[j]<<endl;
            }
            else if(c[j].size()<2 && c[j].size()>=1){
                cout<<"000"<<c[j]<<"\t"<<x[j]<<"\t"<<y[j]<<"\t"<<z[j]<<" "<<h[j]<<endl;
            }
            else if(c[j].size()<3 ){
                cout<<"00"<<c[j]<<"\t"<<x[j]<<"\t"<<y[j]<<"\t"<<z[j]<<" "<<h[j]<<endl;
            }
            else {
                cout<<c[j]<<"\t"<<x[j]<<"\t"<<y[j]<<"\t"<<z[j]<<" "<<h[j]<<endl;
            }
        }
        else{
           if(c[j].size()<1){
                cout<<"0000"<<c[j]<<"\t"<<x[j]<<"\t"<<y[j]<<"\t"<<z[j]<<"\t "<<h[j]<<endl;
            }
            else if(c[j].size()<2 && c[j].size()>=1){
                cout<<"000"<<c[j]<<"\t"<<x[j]<<"\t"<<y[j]<<"\t"<<z[j]<<"\t "<<h[j]<<endl;
            }
            else if(c[j].size()<3 ){
                cout<<"00"<<c[j]<<"\t"<<x[j]<<"\t"<<y[j]<<"\t"<<z[j]<<"\t "<<h[j]<<endl;
            }
            else {
                cout<<c[j]<<"\t"<<x[j]<<"\t"<<y[j]<<"\t"<<z[j]<<"\t "<<h[j]<<endl;
            }
        }




	}

    return 0;
}
