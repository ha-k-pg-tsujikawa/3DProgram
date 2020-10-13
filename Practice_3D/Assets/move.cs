using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class move : MonoBehaviour
{
    bool IsFirst = true;
    bool IsStart = true;
    bool IsSide = true;

    float side_speed = 0.0f;
    float vertical_speed = 0.0f;

    int timecount = 0;
    int side_step = 0;
    int vertical_step = 0;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void FixedUpdate()
    {
        transform.Translate(side_speed, 0.0f, vertical_speed);

        timecount++;
        if (IsSide)
        {
            if (timecount % 60 == 0 && IsStart == true)
            {
                side_step++;
                if (side_step == 3)
                {
                    side_step = 0;
                    IsStart = false;
                }
            }
            else if (timecount % 60 == 0)
            {
                side_step--;
                if (IsFirst == true)
                {
                    side_step = 2;
                    IsFirst = false;
                }

                if (side_step == 0)
                {
                    timecount = 0;
                    IsFirst = true;
                    IsStart = true;
                    IsSide = false;
                }
            }
        }
        else
        {
            if (timecount % 60 == 0 && IsStart == true)
            {
                vertical_step++;
                if (vertical_step == 3)
                {
                    vertical_step = 0;
                    IsStart = false;
                }
            }
            else if (timecount % 60 == 0)
            {
                vertical_step--;
                if (IsFirst == true)
                {
                    vertical_step = 2;
                    IsFirst = false;
                }

                if (vertical_step == 0)
                {
                    timecount = 0;
                    IsFirst = true;
                    IsStart = true;
                    IsSide = true;
                }
            }
        }

        switch (side_step)
        {
            case 0:
                side_speed = 0.0f;
                break;
            case 1:
                side_speed = 0.02f;
                break;
            case 2:
                side_speed = -0.02f;
                break;
            case 3:
                vertical_speed = 0.0f;
                break;         
            case 4:            
                vertical_speed = 0.02f;
                break;         
            case 5:            
                vertical_speed = -0.02f;
                break;
        }

        switch (vertical_step)
        {
            case 0:
                vertical_speed = 0.0f;
                break;
            case 1:
                vertical_speed = 0.02f;
                break;
            case 2:
                vertical_speed = -0.02f;
                break;
            case 3:
                break;
        }

        }
    }
