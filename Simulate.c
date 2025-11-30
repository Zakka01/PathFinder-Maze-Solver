#define LEFT_MOTOR_PIN 12
#define RIGHT_MOTOR_PIN 13


#define LEFT 12
#define RIGHT_MOTOR_PIN 13




// #define HIGH 0
// #define LOW 1

typedef struct s_list
{
    int left;
    int right;
    int center;
} poss;

poss table[100];
int iposs = 0;

void ft_pos(int *l, int *c, int *r)
{
    // pinMode(l, HIGH);
    // pinMode(c, HIGH);
    // pinMode(r, HIGH);
}


// reading 2 sensors at the same time, | Crossroad |
int ft_mulch(int l, int c, int r)
{
    int count = l + c + r;

    if (count >= 2)
        return 1;
    return 0;
}

void SetMotorSpeed(int lWheel, int rWheel)
{
    // control valid range limits first between 0 & 255
    if (lWheel > 255) lWheel = 255;
    if (rWheel > 255) rWheel = 255;
    if (lWheel < 0) lWheel = 0;
    if (rWheel < 0) rWheel = 0; 

    // control motor speed
    analogWrite(LEFT_MOTOR_PIN, lWheel);
    analogWrite(RIGHT_MOTOR_PIN, rWheel);

}

void move_forward()
{
    SetMotorSpeed(250, 250);
}

void move_right()
{
    SetMotorSpeed(170, 50);
}

void move_left()
{
    SetMotorSpeed(50, 170);
}

void turnback()
{
    SetMotorSpeed(0, 250);
    delay(500);
}


void loop()
{
    int l;
    int c;
    int r;
    poss *cp;

    ft_pos(&l, &c, &r);

    // if not a CrossRoad do this 
    if (!ft_mulch(l, c, r))
    {
        if (c == 1)
            move_forward();
        else if (r == 1)
            move_right();
        else if (l == 1)
            move_left();
        return;
    }

    // if its a CrossRoad store the values on the struct
    cp = &table[iposs];
    cp->left = l;
    cp->center = c;
    cp->right = r;

    // First Choice : if forward is available move forward
    if (cp->center == 1)
    {
        ft_forward();
        iposs++;
        delay(500);
        return;
    }
    // Second Choice : if left is available move left
    if (cp->left == 1)
    {
        ft_left();
        iposs++;
        delay(500);
        return;
    }
    // Last Choice : then if right is available move right    
    if (cp->right == 1)
    {
        ft_right();
        iposs++;
        delay(500);
        return;
    }
    // if Nothing is available | DeadEnd | then turnBack 
    ft_turnback();
    iposs--;
    delay(1000);
}
