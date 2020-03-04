#include <iostream>
#include <string>

using namespace std;

//  conclusion list
string conclt[16];

// variable list
string varlt[16];

//  clause vairable list
string clvarlt[64];

string varble;

//conclusion list variables
string  majorr = "null", numbers = "null", manage = "null", lang = "null", construct = "null", socials = "null";

//variable list variables
string school = "null",
        probsol = "null",
        experi = "null",
        leadership = "null",
        read = "null",
        write = "null",
        machine = "null",
        arch = "null",
        hist = "null",
        gov = "null",
        fine = "null",
        ppl = "null",
        volunteer = "null",
        publics = "null",
        teaching = "null",
        create = "null";


/* instantiated list */
int instlt[17];
/* statement stack */
int statsk[17];
int /* clause stack */ clausk[17], sn, f, i, ss, j,/*stack pointer */ sp;

void determine_member_concl_list();
void push_on_stack();
void instantiate();

int backward()
{
    /***** initialization section ******/
    /* stack space is 10 we initially place stack space at 10+1 */
    sp=17;
    for (i=1; i<17; i++)
    {
        conclt[i] = "null";
        varlt[i] = "null";
        instlt[i]=0;
        statsk[i]=0;
        clausk[i]=0;
    }
    for (i=0; i<16; i++)
    {

        clvarlt[i] = "null";

    }
    /* enter conclusions which are the variables in the then part,
1 at
    a time.  enter the conclusions in exact order starting at the 1st
    if-then.  after last conclusion hit return key for rest of
    conclusions */

    //concluion list
    conclt[0] = "MAJOR";
    conclt[1] = "NUMBERS";
    conclt[2] = "MANAGEMENT";
    conclt[3] = "LANG";
    conclt[4] = "CONSTRUCT";
    conclt[5] = "SOCIALS";
    conclt[6] = "ENGINEERING";
    conclt[7] = "LIBERAL ARTS";
    conclt[8] = "HEALTH";
    conclt[9] = "SCIENCE";
    conclt[10] = "FINE ARTS";
    conclt[11] = "BUSINESS";
    conclt[12] = "APPLIED ARTS";
    conclt[13] = "COMMUNICATIONS";
    conclt[14] = "EDUCATION";
    conclt[15] = "MATH";

    //variable list
    varlt[0] = "school";
    varlt[1] = "probsol";
    varlt[2] = "experi";
    varlt[3] = "leadership";
    varlt[4] = "read";
    varlt[5] = "write";
    varlt[6] = "machine";
    varlt[7] = "arch";
    varlt[8] = "hist";
    varlt[9] = "gov";
    varlt[10] = "fine";
    varlt[11] = "people";
    varlt[12] = "volunteer";
    varlt[13] = "publics";
    varlt[14] = "teaching";
    varlt[15] = "creative";

    //clause variable list
    //where there is null, do not put anything
    clvarlt[0] = school;
    clvarlt[4] = probsol;
    clvarlt[8] = leadership;
    clvarlt[12] = read;
    clvarlt[13] = write;
    clvarlt[16] = machine;
    clvarlt[17] = arch;
    clvarlt[20] = hist;
    clvarlt[21] = gov;
    clvarlt[24] = school;
    clvarlt[25] = numbers;
    clvarlt[26] = construct;
    clvarlt[28] = school;
    clvarlt[29] = lang;
    clvarlt[32] = school;
    clvarlt[33] = numbers;
    clvarlt[34] = ppl;
    clvarlt[35] = volunteer;
    clvarlt[36] = school;
    clvarlt[37] = numbers;
    clvarlt[38] = experi;
    clvarlt[40] = school;
    clvarlt[41] = create;
    clvarlt[42] = fine;
    clvarlt[44] = school;
    clvarlt[45] = numbers;
    clvarlt[46] = manage;
    clvarlt[48] = school;
    clvarlt[49] = ppl;
    clvarlt[50] = socials;
    clvarlt[52] = school;
    clvarlt[53] = ppl;
    clvarlt[54] = publics;
    clvarlt[56] = school;
    clvarlt[57] = ppl;
    clvarlt[58] = teaching;
    clvarlt[60] = school;
    clvarlt[61] = numbers;



    /****** inference section *****/
    //string conclusionWanted;
    cout <<"If you are looking for a major, please type 'MAJOR' and then hit enter     :";
    cin >> varble;
    cout << endl << "Please enter a (Y) for Yes or an (N) for No for every following question. " << endl;

    f=1;
    determine_member_concl_list();

    int rulenum;

    if (sn != 0)
    {
        do
        {
            push_on_stack();
            bool itsdone = true;
            do
            {

                for(j=0;j<16;j++)
                {
                    if(clvarlt[j]!="null")
                        break;
                }

                varble = clvarlt[j];
                if(varble !=  "null")
                {
                    f = 1;
                    determine_member_concl_list();
                    push_on_stack();
                    instantiate();
                    itsdone = true;
                    clausk[sp] = clausk[sp] + 1;
                }
                else
                    instantiate();
            } while(!itsdone); /*do-while*/
            sn = statsk[i];
            ss = 0;

            /**** if  statements ****/

            switch (sn)
            {
                case 1:
                    if(school == "NO")
                        ss = 1;
                    rulenum=1;
                    break;
                case 2:
                    if(probsol == "YES")
                        ss = 1;
                    rulenum=2;
                    break;
                case 3:
                    if(leadership == "YES")
                        ss =1;
                    rulenum=3;
                    break;
                case 4:
                    if((read == "YES") &&(write == "YES"))
                        ss = 1;
                    rulenum=4;
                    break;
                case 5:
                    if((machine == "YES")  && (arch == "YES"))
                        ss = 1;
                    rulenum=5;
                    break;
                case 6: if((hist == "YES")  && (gov == "YES"))
                        ss = 1;
                    rulenum=6;
                    break;
                case 7: if((school == "YES")  && (numbers == "YES") && (construct == "YES"))
                        ss = 1;
                    rulenum=7;
                    break;
                case 8: if((school == "YES")  && (lang == "YES"))
                        ss = 1;
                    rulenum=8;
                    break;
                case 9: if((school == "YES")  && (numbers == "YES") && (ppl == "YES") && (volunteer == "YES"))
                        ss = 1;
                    rulenum=9;
                    break;
                case 10: if((school == "YES")  && (numbers == "YES") && (experi == "YES"))
                        ss = 1;
                    rulenum=10;
                    break;
                case 11: if((school == "YES")  && (create == "YES") && (fine == "YES"))
                        ss = 1;
                    rulenum=11;
                    break;
                case 12: if((school == "YES")  && (numbers == "YES") && (manage == "YES"))
                        ss = 1;
                    rulenum=12;
                    break;
                case 13: if((school == "YES")  && (ppl == "YES") && (socials == "YES"))
                        ss = 1;
                    rulenum=13;
                    break;
                case 14: if((school == "YES")  && (ppl == "YES") && (publics == "YES"))
                        ss = 1;
                    rulenum=14;
                    break;
                case 15: if((school == "YES")  && (ppl == "YES") && (teaching == "YES"))
                        ss = 1;
                    rulenum=15;
                    break;
                case 16: if((school == "YES")  && (numbers == "YES"))
                        ss = 1;
                    rulenum=16;
                    break;
                default :
                    cout<< "ERROR - program did not complete as expected 1" << endl;
                    return -1;
            }

            if( ss != 1)
            {
                i = statsk[sp];
                varble = conclt[i];
                f = statsk[sp] + 1;
                determine_member_concl_list();
                sp = sp+1;
            }
        } while(ss!=1);

        if(sn != 0)
        {
            /**** then statements ****/
            switch (rulenum)
            {
                case 1: majorr = "NO";
                    break;
                case 2: numbers = "YES";
                    break;
                case 3: manage = "YES";
                    break;
                case 4: lang = "YES";
                    break;
                case 5: construct = "YES";
                    break;
                case 6: socials = "YES";
                    break;
                case 7: majorr = "ENGINEERING";
                    cout << majorr;
                    break;
                case 8: majorr = "LIBERAL ARTS";
                    cout << majorr;
                    break;
                case 9: majorr = "HEALTH";
                    cout << majorr;
                    break;
                case 10: majorr = "SCIENCE";
                    cout << majorr;
                    break;
                case 11: majorr = "FIN ARTS";
                    cout << majorr;
                    break;
                case 12: majorr = "BUSINESS";
                    cout << majorr;
                    break;
                case 13: majorr = "APPLIED ARTS";
                    cout << majorr;
                    break;
                case 14: majorr = "COMMUNICATIONS";
                    cout << majorr;
                    break;
                case 15: majorr = "EDUCATION";
                    cout << majorr;
                    break;
                case 16: majorr = "MATH";
                    cout << majorr;
                    break;
                default :
                    cout<< "ERROR - program did not complete as expected 2" << endl;
                    break;
            }
            /* pop the stack */
            sp=sp+1;
            if(sp >= 16)
            {
                goto bdone;
            }
            else
            {
                clausk[sp] = clausk[sp]+1;
            }
        }
    }

    bdone: cout << endl << endl
                <<"From all of the questions you answered, you might be a " <<majorr<< " major."
                << endl
                <<"Now we will help you decide what area you might be inetredted in within " << majorr << ". "
                << endl
                << endl;

    return 0;
}

void determine_member_concl_list( )
{
    sn = 0;
    i = f;

    for(int w=0;w<16;w++)
    {
        if(conclt[w] == varble)
        {
            sn = w+1;
            break;
        }
    }
}

void push_on_stack()
{
    sp=sp-1;
    statsk[sp] = sn;

    clausk[sp] = 1;
}

void instantiate()
{
    i = 0;
    for(int g = 0; g < 16; g++)
    {
        if((varble == varlt[g]) && (instlt[g] != 1))
            i=g;
    }
    while((varble !=varlt[i]) && (i<17))
    {
        i = i + 1;
        while (instlt[i] != 1)
        {
            instlt[i] = 1;
            char ans;
            switch (i)
            {
                case 1:
                    cout << endl << "Do you like school? " << endl;

                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        school = "YES";
                    else
                        school = "NO";
                    break;
                case 2:
                    cout << "Are you good at problem solving? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        probsol = "YES";
                    else
                        probsol = "NO";
                    break;
                case 3:
                    cout << "Do you like experiments? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        experi = "YES";
                    else
                        experi = "NO";
                    break;
                case 4:
                    cout << "Are you comfortable with leadership roles? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        leadership = "YES";
                    break;
                case 5:
                    cout << "Do you like reading? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        read = "YES";
                    else
                        read = "NO";
                    break;
                case 6:
                    cout << "Do you like writing? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        write = "YES";
                    else
                        write = "NO";
                    break;
                case 7:
                    cout << "Are you interested in machinery? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        machine = "YES";
                    else
                        machine = "NO";
                    break;
                case 8:
                    cout << "Do you like architecture? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        arch = "YES";
                    else
                        arch = "NO";
                    break;
                case 9:
                    cout << "Are you intetesed in history? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        hist = "YES";
                    else
                        hist = "NO";
                    break;
                case 10:
                    cout << "Does government interest you? " << endl;

                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        gov = "YES";
                    else
                        gov = "NO";
                    break;
                case 11:
                    cout << "Do you appreciate the theatre and other fine arts? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        fine = "YES";
                    else
                        fine = "NO";
                    break;
                case 12:
                    cout << "Do you like helping poeple? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        ppl = "YES";
                    else
                        ppl = "NO";
                    break;
                case 13:
                    cout << "Do you like volunteering? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        volunteer = "YES";
                    else
                        volunteer = "NO";
                    break;
                case 14:
                    cout << "Are you comfortable with public speaking? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        publics = "YES";
                    else
                        publics = "NO";
                    break;
                case 15:
                    cout << "Do you like teaching? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        teaching = "YES";
                    else
                        teaching = "NO";
                    break;
                case 16:
                    cout << "Would you consider yourself a creative person? " << endl;
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y')
                        create = "YES";
                    else
                        create = "NO";
                    break;
                default :
                    cout << "ERROR - program did not complete as expected 3" << endl;
                    break;
            }
        }
    }
}