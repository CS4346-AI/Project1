/*** FORWARD CHAINING ***/
/************************/
/* Install your IF clauses in sequence in the middle of
the program within the first case statement.
EXAMPLE: IF ((A1==2) && (A2==6) || (A3 == 'YES')) S-1;
IF (J=='NO') S-1;

The THEN part of the above construction always contains
S-1. Install your THEN clauses in sequence in the middle
of the program within the second case statement. */

#include <iostream>
using namespace std;

string condition_var_queue[70];     /* condition variable queue */
string variable_list[10][7];        // 10 majors and 7 variables used in each major
string clause_variable_list[200];   // (10 majors * 5 rules * 4 spaces = 200)

string var;     // variable
string area;    // i.e. Astronomy, Nursing, Marketing, etc.
string natural, space, motion, organisms, composition, reactions, earth;        // SCIENCE
string aid, health, teeth, eyes, research, drugs, animals;                      // HEALTH
string money, recording, large_sums, wealth, people, leader, promoting;         // BUSINESS
string pure, variables, shapes, natural_nums, practical, proofs, data;          // MATH
string design, code, electric, infra, discover, manufacture, nuclear;           // ENGINEERING
string stage, drama, rhythm, compose, behind, creative, art_history;            // FINE ARTS
string young, crafts, passion, basics, old, middle, high;                       // EDUCATION
string learning, mind, morals, identity, studying, reading, writing;            // LIBERAL ARTS
string pub, politics, convincing, image, priv, language, news;                  // COMM
string family, problems, management, communities, community, justice, military; // APPLIED ARTS

int instantiated_list[70];  /* instantiated list of variables */
int s;

void search(int*, int, int*, int*);
void check_instantiation(string);
void instantiate(string, int);

int main()
{
    /******** INITIALIZATION SECTION ***********/
    for (int i = 0; i < 10; i++)
    {
        condition_var_queue[i] = "";

        for (int k = 0; k < 7; k++)
        {
            variable_list[i][k] = "";
        }

        instantiated_list[i] = 0;
    }

    for (int i = 0; i < 200; i++)
    {
        clause_variable_list[i] = "";
    }

    /* enter variables which are in the IF part, 1 at a time in
    the exact order that they occur. Up to 3 variables per
    IF statement. Do not duplicate any variable names. Any
    name is used only once. If no more variables left, just
    hit return key */

    /* VARIABLE LIST */

    // SCIENCE
    variable_list[0][0] = "natural";
    variable_list[0][1] = "space";
    variable_list[0][2] = "motion";
    variable_list[0][3] = "organisms";
    variable_list[0][4] = "composition";
    variable_list[0][5] = "reactions";
    variable_list[0][6] = "earth";

    // HEALTH
    variable_list[1][0] = "aid";
    variable_list[1][1] = "health";
    variable_list[1][2] = "teeth";
    variable_list[1][3] = "eyes";
    variable_list[1][4] = "research";
    variable_list[1][5] = "drugs";
    variable_list[1][6] = "animals";

    // BUSINESS
    variable_list[2][0] = "money";
    variable_list[2][1] = "recording";
    variable_list[2][2] = "large sums";
    variable_list[2][3] = "wealth";
    variable_list[2][4] = "people";
    variable_list[2][5] = "leader";
    variable_list[2][6] = "promoting";

    // MATH
    variable_list[3][0] = "pure";
    variable_list[3][1] = "variables";
    variable_list[3][2] = "shapes";
    variable_list[3][3] = "natural";
    variable_list[3][4] = "practical";
    variable_list[3][5] = "proofs";
    variable_list[3][6] = "data";

    // ENGINEERING
    variable_list[4][0] = "design";
    variable_list[4][1] = "code";
    variable_list[4][2] = "electric";
    variable_list[4][3] = "infra";
    variable_list[4][4] = "discover";
    variable_list[4][5] = "manufacture";
    variable_list[4][6] = "nuclear";

    // FINE ARTS
    variable_list[5][0] = "stage";
    variable_list[5][1] = "drama";
    variable_list[5][2] = "rhythm";
    variable_list[5][3] = "compose";
    variable_list[5][4] = "behind";
    variable_list[5][5] = "creative";
    variable_list[5][6] = "art history";

    // EDUCATION
    variable_list[6][0] = "young";
    variable_list[6][1] = "crafts";
    variable_list[6][2] = "passion";
    variable_list[6][3] = "basics";
    variable_list[6][4] = "old";
    variable_list[6][5] = "middle";
    variable_list[6][6] = "high";

    // LIBERAL ARTS
    variable_list[7][0] = "learning";
    variable_list[7][1] = "mind";
    variable_list[7][2] = "morals";
    variable_list[7][3] = "identity";
    variable_list[7][4] = "studying";
    variable_list[7][5] = "reading";
    variable_list[7][6] = "writing";

    // COMM
    variable_list[8][0] = "public";
    variable_list[8][1] = "politics";
    variable_list[8][2] = "convincing";
    variable_list[8][3] = "image";
    variable_list[8][4] = "private";
    variable_list[8][5] = "language";
    variable_list[8][6] = "news";

    // APPLIED ARTS
    variable_list[9][0] = "family";
    variable_list[9][1] = "problems";
    variable_list[9][2] = "management";
    variable_list[9][3] = "communities";
    variable_list[9][4] = "community";
    variable_list[9][5] = "justice";
    variable_list[9][6] = "military";

    cout <<  "*** VARIABLE LIST ***" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 7; j++) {
            cout << "ENTER VARIABLE [" << i << "][" << j << "]: " << variable_list[i][j] << endl;
        }
        cout << endl;
    }
    cout << "HIT RETURN TO CONTINUE";
    cin.ignore();


    /* enter variables as they appear in the IF clauses, Up to 3
    variables per IF statement. If no more variables left, just
    hit return key */

    /* CLAUSE VARIABLE LIST */

    // SCIENCE
    clause_variable_list[0] = "natural";
    clause_variable_list[1] = "space";
    clause_variable_list[4] = "natural";
    clause_variable_list[5] = "motion";
    clause_variable_list[8] = "natural";
    clause_variable_list[9] = "organisms";
    clause_variable_list[12] = "composition";
    clause_variable_list[13] = "reactions";
    clause_variable_list[16] = "composition";
    clause_variable_list[17] = "earth";

    // HEALTH
    clause_variable_list[20] = "aid";
    clause_variable_list[21] = "health";
    clause_variable_list[24] = "aid";
    clause_variable_list[25] = "teeth";
    clause_variable_list[28] = "aid";
    clause_variable_list[29] = "eyes";
    clause_variable_list[32] = "research";
    clause_variable_list[33] = "drugs";
    clause_variable_list[36] = "research";
    clause_variable_list[37] = "animals";

    // BUSINESS
    clause_variable_list[40] = "money";
    clause_variable_list[41] = "recording";
    clause_variable_list[44] = "money";
    clause_variable_list[45] = "large sums";
    clause_variable_list[48] = "money";
    clause_variable_list[49] = "wealth";
    clause_variable_list[52] = "people";
    clause_variable_list[53] = "leader";
    clause_variable_list[56] = "people";
    clause_variable_list[57] = "promoting";

    // MATH
    clause_variable_list[60] = "pure";
    clause_variable_list[61] = "variables";
    clause_variable_list[64] = "pure";
    clause_variable_list[65] = "shapes";
    clause_variable_list[68] = "pure";
    clause_variable_list[69] = "natural sums";
    clause_variable_list[72] = "practical";
    clause_variable_list[73] = "proofs";
    clause_variable_list[76] = "practical";
    clause_variable_list[77] = "data";

    // ENGINEERING
    clause_variable_list[80] = "design";
    clause_variable_list[81] = "code";
    clause_variable_list[84] = "design";
    clause_variable_list[85] = "electric";
    clause_variable_list[88] = "design";
    clause_variable_list[89] = "infra";
    clause_variable_list[92] = "discover";
    clause_variable_list[93] = "manufacture";
    clause_variable_list[96] = "discover";
    clause_variable_list[97] = "nuclear";

    // FINE ARTS
    clause_variable_list[100] = "stage";
    clause_variable_list[101] = "drama";
    clause_variable_list[104] = "stage";
    clause_variable_list[105] = "rhythm";
    clause_variable_list[108] = "stage";
    clause_variable_list[109] = "compose";
    clause_variable_list[112] = "behind";
    clause_variable_list[113] = "creative";
    clause_variable_list[116] = "behind";
    clause_variable_list[117] = "art history";

    // EDUCATION
    clause_variable_list[120] = "young";
    clause_variable_list[121] = "crafts";
    clause_variable_list[124] = "young";
    clause_variable_list[125] = "passion";
    clause_variable_list[128] = "young";
    clause_variable_list[129] = "basics";
    clause_variable_list[132] = "old";
    clause_variable_list[133] = "middle";
    clause_variable_list[136] = "old";
    clause_variable_list[137] = "high";

    // LIBERAL ARTS
    clause_variable_list[140] = "learning";
    clause_variable_list[141] = "mind";
    clause_variable_list[144] = "learning";
    clause_variable_list[145] = "morals";
    clause_variable_list[148] = "learning";
    clause_variable_list[149] = "identity";
    clause_variable_list[152] = "studying";
    clause_variable_list[153] = "reading";
    clause_variable_list[156] = "studying";
    clause_variable_list[157] = "writing";

    // COMM
    clause_variable_list[160] = "public";
    clause_variable_list[161] = "politics";
    clause_variable_list[164] = "public";
    clause_variable_list[165] = "convincing";
    clause_variable_list[168] = "public";
    clause_variable_list[169] = "image";
    clause_variable_list[172] = "private";
    clause_variable_list[173] = "language";
    clause_variable_list[176] = "private";
    clause_variable_list[177] = "news";

    // APPLIED ARTS
    clause_variable_list[180] = "family";
    clause_variable_list[181] = "problems";
    clause_variable_list[184] = "family";
    clause_variable_list[185] = "management";
    clause_variable_list[188] = "family";
    clause_variable_list[189] = "communities";
    clause_variable_list[192] = "community";
    clause_variable_list[193] = "justice";
    clause_variable_list[196] = "community";
    clause_variable_list[197] = "military";

    cout <<  "*** CLAUSE-VARIABLE LIST ***" << endl;
    int k;
    for (int i = 0; i < 50; i++)
    {
        cout << "** CLAUSE " << i+1 << endl;
        for (int j = 0; j < 4; j++)
        {
            k = 4 * ((i+1) - 1) + (j+1);
            cout << "VARIABLE " << j+1 << ": " << clause_variable_list[k-1] << endl;
        }
    }
    cout << "HIT RETURN TO CONTINUE";
    cin.ignore();

    /****** INFERENCE SECTION *****************/
    string user_input;
    cout << "\nENTER CONDITION VARIABLE? ";
    cin >> user_input;

    /* place condition variable user_input on condition var queue */
    int fp = 1; // front pointer
    int bp = 1; // back pointer
    condition_var_queue[bp] = user_input;

    /* move back pointer (bp) to the back */
    bp++;

    /* set the condition variable pointer consisting of the
    statement number (sn) and the clause number (cn) */
    int sn = 1; // statement number
    int cn = 1; // clause number

    /* find the next statement number containing the condition variable
    which is in front of the queue (condition_var_queue), this statement number
    is located in the clause variable list (clause_variable_list) */

    /* start at the beginning */
    int front = 1;
    int clause = 0;

    cout << "START SEARCH" << endl;
    b496: search(&sn, cn, &front, &fp);
    cout << "END SEARCH" << endl;
    /* point to first clause in statement */
    cn = 1;
    if (sn != 0)
        /* more statements */
    {
        cout << "cn = " << cn << endl;
        cout << "sn = " << sn << endl;
        /* locate the clause */
        clause = 4 * (sn-1) + cn;
        cout << "clause = 4 * (sn - 1) + cn = " << clause << endl;

        /* clause variable */
        var = clause_variable_list[clause-1];
        cout << "var = clause_variable_list[clause-1] = " << var << endl;

        /* are there any more clauses for this statement */
        cout << "var == \"\"? " << var.empty() << endl;
        while (!var.empty())
            /* more clauses */
        {
            cout << "entered while" << endl;
            /* check instantiation of this clause */
            check_instantiation(var);
            cout << "finished check_instantiation" << endl;
            cn++;

            /* check next clause */
            clause = 4 * (sn-1) + cn;
            var = clause_variable_list[clause-1];
        }

        /* no more clauses - check IF part of statement */
        s = 0;

        /* sample IF-THEN statements from the position knowledge base */
        switch(sn)
        {
            case 1:
                if (natural == "YES" && space == "YES") s = 1;
                break;
            case 2:
                if (natural == "YES" && motion == "YES") s = 1;
                break;
            case 3:
                if (natural == "YES" && organisms == "YES") s = 1;
                break;
            case 4:
                if (composition == "YES" && reactions == "YES") s = 1;
                break;
            case 5:
                if (composition == "YES" && earth == "YES") s = 1;
                break;
            case 6:
                if (aid == "YES" && health == "YES") s = 1;
                break;
            case 7:
                if (aid == "YES" && teeth == "YES") s = 1;
                break;
            case 8:
                if (aid == "YES" && eyes == "YES") s = 1;
                break;
            case 9:
                if (research == "YES" && drugs == "YES") s = 1;
                break;
            case 10:
                if (research == "YES" && animals == "YES") s = 1;
                break;
            case 11:
                if (money == "YES" && recording == "YES") s = 1;
                break;
            case 12:
                if (money == "YES" && large_sums == "YES") s = 1;
                break;
            case 13:
                if (money == "YES" && wealth == "YES") s = 1;
                break;
            case 14:
                if (people == "YES" && leader == "YES") s = 1;
                break;
            case 15:
                if (people == "YES" && promoting == "YES") s = 1;
                break;
            case 16:
                if (pure == "YES" && variables == "YES") s = 1;
                break;
            case 17:
                if (pure == "YES" && shapes == "YES") s = 1;
                break;
            case 18:
                if (pure == "YES" && natural_nums == "YES") s = 1;
                break;
            case 19:
                if (practical == "YES" && proofs == "YES") s = 1;
                break;
            case 20:
                if (practical == "YES" && data == "YES") s = 1;
                break;
            case 21:
                if (design == "YES" && code == "YES") s = 1;
                break;
            case 22:
                if (design == "YES" && electric == "YES") s = 1;
                break;
            case 23:
                if (design == "YES" && infra == "YES") s = 1;
                break;
            case 24:
                if (discover == "YES" && manufacture == "YES") s = 1;
                break;
            case 25:
                if (discover == "YES" && nuclear == "YSE") s = 1;
                break;
            case 26:
                if (stage == "YES" && drama == "YES") s = 1;
                break;
            case 27:
                if (stage == "YES" && rhythm == "YES") s = 1;
                break;
            case 28:
                if (stage == "YES" && compose == "YES") s = 1;
                break;
            case 29:
                if (behind == "YES" && creative == "YES") s = 1;
                break;
            case 30:
                if (behind == "YES" && art_history == "YES") s = 1;
                break;
            case 31:
                if (young == "YES" && crafts == "YES") s = 1;
                break;
            case 32:
                if (young == "YES" && passion == "YES") s = 1;
                break;
            case 33:
                if (young == "YES" && basics == "YES") s = 1;
                break;
            case 34:
                if (old == "YES" && middle == "YES") s = 1;
                break;
            case 35:
                if (old == "YES" && high == "YES") s = 1;
                break;
            case 36:
                if (learning == "YES" && mind == "YES") s = 1;
                break;
            case 37:
                if (learning == "YES" && morals == "YES") s = 1;
                break;
            case 38:
                if (learning == "YES" && identity == "YES") s = 1;
                break;
            case 39:
                if (studying == "YES" && reading == "YES") s = 1;
                break;
            case 40:
                if (studying == "YES" && writing == "YES") s = 1;
                break;
            case 41:
                if (pub == "YES" && politics == "YES") s = 1;
                break;
            case 42:
                if (pub == "YES" && convincing == "YES") s = 1;
                break;
            case 43:
                if (pub == "YES" && image == "YES") s = 1;
                break;
            case 44:
                if (priv == "YES" && language == "YES") s = 1;
                break;
            case 45:
                if (priv == "YES" && news == "YES") s = 1;
                break;
            case 46:
                if (family == "YES" && problems == "YES") s = 1;
                break;
            case 47:
                if (family == "YES" && management == "YES") s = 1;
                break;
            case 48:
                if (family == "YES" && communities == "YES") s = 1;
                break;
            case 49:
                if (community == "YES" && justice == "YES") s = 1;
                break;
            case 50:
                if (community == "YES" && military == "YES") s = 1;
                break;
            default:
                cout << "ERROR - Try Again" << endl;
                return -1;
        }

        /* see if the THEN part should be invoked (s = 1) */
        if (s != 1)
        {
            front = sn + 1;
            goto b496;
        }

        /* invoke THEN part */
        switch (sn)
        {
            /* put variable on the conclusion variable queue */
            case 1:
                area = "Astronomy";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var, bp);
                break;
                /* put variable on the conclusion variable queue */
            case 2:
                area = "Physics";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var, bp);
                break;
                /* put variable on the conclusion variable queue */
            case 3:
                area = "Biology";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var, bp);
                break;
                /* put variable on the conclusion variable queue */
            case 4:
                area = "Chemistry";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var, bp);
                break;
                /* put variable on the conclusion variable queue */
            case 5:
                area = "Geology";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var, bp);
                break;
            case 6:
                area = "Nursing";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 7:
                area = "Dentistry";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 8:
                area = "Optometry";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 9:
                area = "Pharmaceutical Research";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 10:
                area = "Veterinary";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 11:
                area = "Accounting";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 12:
                area = "Finance";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 13:
                area = "Economics";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 14:
                area = "Management";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 15:
                area = "Marketing";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 16:
                area = "Algebra";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 17:
                area = "Geometry";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 18:
                area = "Number Theory";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 19:
                area = "Applied Mathematics";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 20:
                area = "Statistics";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 21:
                area = "Computer Engineering";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 22:
                area = "Electrical Engineering";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 23:
                area = "Civil Engineering";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 24:
                area = "Chemical Engineering";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 25:
                area = "Nuclear Engineering";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 26:
                area = "Theatre";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 27:
                area = "Dance";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 28:
                area = "Music";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 29:
                area = "Studio Art";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 30:
                area = "Art History";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 31:
                area = "Preschool Education";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 32:
                area = "Special Education";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 33:
                area = "Elementary Education";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 34:
                area = "Middle School Education";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 35:
                area = "High School Education";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 36:
                area = "Psychology";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 37:
                area = "Philosophy";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 38:
                area = "Gender Studies";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 39:
                area = "History";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 40:
                area = "English";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 41:
                area = "Politics";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 42:
                area = "Marketing";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 43:
                area = "Public Relations";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 44:
                area = "Multilinguistics";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 45:
                area = "Journalism";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 46:
                area = "Social Work";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 47:
                area = "Organization Management and Leadership";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 48:
                area = "Family Consumer Services";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 49:
                area = "Criminal Justice";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            case 50:
                area = "Military Science";
                cout << "Area of Study = " << area << endl;
                var = "area";
                instantiate(var , bp);
                break;
            default:
                cout << "ERROR - Try Again" << endl;
                return -1;
        }
        front = sn + 1;
        goto b496;
    }

    /* no more clauses in the clause variable list (clause_variable_list)
     * containing the variable in front of the queue (condition_var_queue(fp))
     * then remove front variable (condition_var_queue(fp)) and replace it by
     * the next variable (condition_var_queue(fp+1)).
     * If no more variables are at the front of the queue, stop.
     */

    /* next queue variable */
    fp++;
    if (fp < bp)
    {
        /* check out the condition variable */
        front = 1;
        goto b496;
    }
    /* no more conclusion variables on queue */
    return 0;
}

//==========================================================================
/* Routine to instantiate a variable if it isn't already.
 * The instantiate indication (instantiated_list) is a 0 if not instantiated, and a 1 if it is.
 * The variable list (variable_list) contains the variable (variable).
 */
void check_instantiation(string variable)
{
    cout << "check_instantiation" << endl;
    /* find variable in the variable list */
    int counter = 0;
    int x = 0;
    int y;
    while (x < 10)
    {
        y = 0;
        cout << "counter = " << counter << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "variable = " << variable << endl;
        cout << "variable_list[x][y] = " << variable_list[x][y] << endl;
        while ((variable != variable_list[x][y]) && (y < 7))
        {
            counter++;
            y++;
            cout << "counter++ = " << counter << endl;
            cout << "y++ = " << y << endl;
        }
        if ((variable == variable_list[x][y]) && (y < 7))
        {
            x = 10;
            cout << "they match!!!" << endl;
        }
        x++;
    }
    cout << "exit the instantiation while loop" << endl;
    /* check if already instantiated */
    cout << "counter is now " << counter << endl;
    cout << "instantiated_list[counter] = " << instantiated_list[counter] << endl;
    if (instantiated_list[counter] == 0)
    {
        /* mark instantiated */
        instantiated_list[counter] = 1;

        /* the designer of this knowledge base places the input
        statements to instantiate the variables in this case
        statement */

        // counter = which variable is it in the variable list
        // ex: counter = 1 is natural, counter = 2 is outer space, etc.
        switch (counter)
        {
            /* input statements for sample position knowledge base */
            // user responds with YES or NO
            case 1:
                cout << "Are you interested in natural science? ";
                cin >> natural;
                break;
            case 2:
                cout << "Do you like outer space? ";
                cin >> space;
                break;
            case 3:
                cout << "Are you curious about the motion and behavior of matter? ";
                cin >> motion;
                break;
            case 4:
                cout << "Are you interested in the composition of living organisms? ";
                cin >> organisms;
                break;
            case 5:
                cout << "Are you interested in composition science? ";
                cin >> composition;
                break;
            case 6:
                cout << "Do chemical reactions fascinate you? ";
                cin >> reactions;
                break;
            case 7:
                cout << "Are you interested in studying the Earth's physical structure? ";
                cin >> earth;
                break;
            case 8:
                cout << "Do you like to provide aid to people in need?";
                cin >> aid;
                break;
            case 9:
                cout << "Do you care for one's overall health?";
                cin >> health;
                break;
            case 10:
                cout << "Does dental work interest you?";
                cin >> teeth;
                break;
            case 11:
                cout << "Are you fascinated by the human eye?";
                cin >> eyes;
                break;
            case 12:
                cout << "Do you like to research how to help living organisms?";
                cin >> research;
                break;
            case 13:
                cout << "Are you interested in drug development?";
                cin >> drugs;
                break;
            case 14:
                cout << "Do you like animals?";
                cin >> animals;
                break;
            case 15:
                cout << "Do you like working with money?";
                cin >> money;
                break;
            case 16:
                cout << "Are you comfortable with recording financial information?";
                cin >> recording;
                break;
            case 17:
                cout << "Can you handle large sums of money?";
                cin >> large_sums;
                break;
            case 18:
                cout << "Are you interested in the production/consumption of wealth?";
                cin >> wealth;
                break;
            case 19:
                cout << "Do you like working with people?";
                cin >> people;
                break;
            case 20:
                cout << "Would you consider yourself as a leader?";
                cin >> leader;
                break;
            case 21:
                cout << "Are you good at promoting products?";
                cin >> promoting;
                break;
            case 22:
                cout << "Do you like pure math?";
                cin >> pure;
                break;
            case 23:
                cout << "Can you solve equations using variables?";
                cin >> variables;
                break;
            case 24:
                cout << "Do you like shapes?";
                cin >> shapes;
                break;
            case 25:
                cout << "Are you interested in studying natural numbers?";
                cin >> natural_nums;
                break;
            case 26:
                cout << "Do you like practical math?";
                cin >> practical;
                break;
            case 27:
                cout << "Do you like equations and proofs?";
                cin >> proofs;
                break;
            case 28:
                cout << "Do you like collecting and analyzing data?";
                cin >> data;
                break;
            case 29:
                cout << "Are you interested in designing a product?";
                cin >> design;
                break;
            case 30:
                cout << "Do you like to code?";
                cin >> code;
                break;
            case 31:
                cout << "Do you like electrical systems?";
                cin >> electric;
                break;
            case 32:
                cout << "Are you interested in infrastructure?";
                cin >> infra;
                break;
            case 33:
                cout << "Are you interested in discovering a product?";
                cin >> discover;
                break;
            case 34:
                cout << "Do you like developing manufacturing processes?";
                cin >> manufacture;
                break;
            case 35:
                cout << "Are you familiar with nuclear physics?";
                cin >> nuclear;
                break;
            case 36:
                cout << "Do you like performing on stage?";
                cin >> stage;
                break;
            case 37:
                cout << "Would you consider yourself dramatic?";
                cin >> drama;
                break;
            case 38:
                cout << "Do you have rhythm?";
                cin >> rhythm;
                break;
            case 39:
                cout << "Do you like to music?";
                cin >> compose;
                break;
            case 40:
                cout << "Would you rather be offstage?";
                cin >> behind;
                break;
            case 41:
                cout << "Do you consider yourself being a creative person?";
                cin >> creative;
                break;
            case 42:
                cout << "Are you interested in the compostition of famous art?";
                cin >> art_history;
                break;
            case 43:
                cout << "Do you like working with younger kids?";
                cin >> young;
                break;
            case 44:
                cout << "Do you like arts and crafts?";
                cin >> crafts;
                break;
            case 45:
                cout << "Would you like to help children with disabilities?";
                cin >> passion;
                break;
            case 46:
                cout << "Would you like to teach elementary education?";
                cin >> electric;
                break;
            case 47:
                cout << "Do you like older kids?";
                cin >> old;
                break;
            case 48:
                cout << "Would you like to teach at middle schools?";
                cin >> middle;
                break;
            case 49:
                cout << "Would you like to teach at high schools?";
                cin >> high;
                break;
            case 50:
                cout << "Do you like to learn?";
                cin >> learning;
                break;
            case 51:
                cout << "Are you interested in learning about the human mind?";
                cin >> mind;
                break;
            case 52:
                cout << "Are you interested in learning about ethics and morals?";
                cin >> learning;
                break;
            case 53:
                cout << "Are you interested in learning about feminism and identities?";
                cin >> identity;
                break;
            case 54:
                cout << "Do you like to study?";
                cin >> studying;
                break;
            case 55:
                cout << "Do you like to read?";
                cin >> reading;
                break;
            case 56:
                cout << "Do you like to write?";
                cin >> writing;
                break;
            case 57:
                cout << "Do you like intercommunication?";
                cin >> pub;
                break;
            case 58:
                cout << "Are you interested in politics?";
                cin >> politics;
                break;
            case 59:
                cout << "Are you able to convince people easily?";
                cin >> convincing;
                break;
            case 60:
                cout << "Are you interested in maintaining a company's public image?";
                cin >> image;
                break;
            case 61:
                cout << "Do you like intracommunication?";
                cin >> priv;
                break;
            case 62:
                cout << "Are you interested in studying langauges?";
                cin >> language;
                break;
            case 63:
                cout << "Do you like to keep up to date with the news?";
                cin >> news;
                break;
            case 64:
                cout << "Do you like helping/working with families?";
                cin >> family;
                break;
            case 65:
                cout << "Do you like to help people with their personal problems?";
                cin >> problems;
                break;
            case 66:
                cout << "Do you like leading people in the right direction?";
                cin >> management;
                break;
            case 67:
                cout << "Do you like helping people make informed decisions?";
                cin >> communities;
                break;
            case 68:
                cout << "Do you like helping/working with communities?";
                cin >> community;
                break;
            case 69:
                cout << "Do you like to serve justice?";
                cin >> justice;
                break;
            case 70:
                cout << "Are you interested in studying about military welfare?";
                cin >> military;
                break;
            default:
                cout << "ERROR - Try Again" << endl;
                break;
        }
    }
    /* end of input statements for the position knowledge base */
}

//==========================================================================
/* Search clause variable list for a variable (clause_variable_list) equal to the
 * one in front of the conclusion queue (condition_var_queue).
 * Return the statement number (sn).
 * If there is no match (if sn = 0), the first statement for the space is f.
 */
void search(int *sn, int cn, int *f, int *fp)
{
    int k = 0;
    int flag = 0;
    *sn = *f;

    while ((flag == 0) && (*sn <= 10))
    {
        cn = 1;
        k = 4 * (*sn-1) + cn;
        while ((clause_variable_list[k-1] != condition_var_queue[*fp]) && (cn < 4))
        {
            cn++;
            k = 4 * (*sn-1) + cn;
        }

        if (clause_variable_list[k-1] == condition_var_queue[*fp])
        {
            flag = 1;
        }

        if (flag == 0)
        {
            sn++;
        }

    }
}

//==========================================================================
/* Routine to instantiate a variable (var) and then place it on the
 * back of the queue (condition_var_queue[bp]), if it is not already there.
 */
void instantiate(string variable, int back_pointer)
{
    /* find variable in the variable list */
    int counter = 0;
    int x = 0;
    int y;
    while (x < 10)
    {
        y = 0;
        while ((variable != variable_list[x][y]) && (y < 7))
        {
            counter++;
            y++;
        }
        if ((variable == variable_list[x][y]) && (y < 7))
        {
            x = 10;
        }
        x++;
    }

    /* instantiate it */
    instantiated_list[counter] = 1;

    /* determine if the variable (var) is or already has been on the queue (condition_var_queue) */
    int q = 0;
    int a = 0;
    while ((variable != condition_var_queue[a]) && (a < 70))
    {
        q++;
        a++;
    }

    /* variable has not been on the queue. Store it in the back of the queue */
    if (variable != condition_var_queue[q])
    {
        condition_var_queue[back_pointer] = variable;
        back_pointer++;
    }
}

//
// Created by Victor Hernandez, Jr. on 3/1/2020.
//