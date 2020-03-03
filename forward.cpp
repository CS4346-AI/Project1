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
string natural, space, motion, organisms, composition, reactions, earth;    // SCIENCE
string aid, health, teeth, eyes, research, drugs, animals;                  // HEALTH
string money, recording, large_sums, wealth, people, leader, promoting;     // BUSINESS

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
    variable_list[0][1] = "outer space";
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

    cout <<  "*** VARIABLE LIST ***" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 7; j++) {
            if (variable_list[i][j].empty())
                continue;
            cout << "ENTER VARIABLE [" << i << "][" << j << "]: " << variable_list[i][j] << endl;
        }
    }
    cout << "HIT RETURN TO CONTINUE";
    cin.ignore();


    /* enter variables as they appear in the IF clauses, Up to 3
    variables per IF statement. If no more variables left, just
    hit return key */

    /* CLAUSE VARIABLE LIST */

    // SCIENCE
    clause_variable_list[0] = "natural";
    clause_variable_list[1] = "outer space";
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

    cout <<  "*** CLAUSE-VARIABLE LIST ***" << endl;
    int k;
    for (int i = 0; i < 200; i++)
    {
        cout << "** CLAUSE " << i+1 << endl;
        for (int j = 0; j < 4; j++)
        {
            k = 4 * ((i+1) - 1) + (j+1);
            if (clause_variable_list[k-1].empty())
                continue;
            cout << "VARIABLE " << j+1 << ": " << clause_variable_list[k-1] << endl;
        }
    }
    cout << "HIT RETURN TO CONTINUE";
    cin.ignore();

    /****** INFERENCE SECTION *****************/
    string user_input;
    cout << "ENTER CONDITION VARIABLE? ";
    cin >> user_input;

    /* place condition variable user_input on condition var queue */
    int fp = 1; // front pointer
    int bp = 1; // back pointer
    condition_var_queue[bp] = user_input;

    /* move back pointer (bp) to the back */
    bp = bp + 1;

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

    b496: search(&sn, cn, &front, &fp);
    /* point to first clause in statement */
    cn = 1;
    if (sn != 0)
        /* more statements */
    {
        /* locate the clause */
        clause = 4 * (sn-1) + cn;

        /* clause variable */
        var = clause_variable_list[clause-1];

        /* are there any more clauses for this statement */
        while (var.empty())
            /* more clauses */
        {
            /* check instantiation of this clause */
            check_instantiation(var);
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
                if (natural == "YES" && space == "YES")
                    s = 1;
                break;
            case 2:
                if (natural == "YES" && motion == "YES")
                    s = 1;
                break;
            case 3:
                if (natural == "YES" && organisms == "YES")
                    s = 1;
                break;
            case 4:
                if (composition == "YES" && reactions == "YES")
                    s = 1;
                break;
            case 5:
                if (composition == "YES" && earth == "YES")
                    s = 1;
                break;
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
    /* check if already instantiated */
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
        while ((clause_variable_list[k] != condition_var_queue[*fp]) && (cn < 4))
        {
            cn++;
            k = 4 * (*sn-1) + cn;
        }

        if (clause_variable_list[k] == condition_var_queue[*fp])
            flag = 1;
        if (flag == 0)
            sn++;
    }
    if (flag == 0)
        *sn = 0; // I'm not too sure about this??
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