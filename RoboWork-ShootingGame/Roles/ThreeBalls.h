/* 
 * kick 3 balls
 */

#define TUI_SPEED Pose2f(80.f, 80.f, 80.f)
#define TUI_TIME 6000

#define TUI_LENGTH -1000.f      // work to right length //// orgin->416.f

#define WORKTOR_TIME 6000

#define KICK_TIME 12000

option(ThreeBalls)
{
    initial_state(start)
    {
        transition
        {
            if (state_time > 3000)
            {
                printf("---> goto workToLeft <---\n");
                goto workToLeft1;
            }
        }
        action
        {
            printf("# state = start #\n");
            theHeadControlMode = HeadControl::lookForward;
            Stand();
        }
    }
    
    state(workToLeft1)
    {
        transition
        {
            if (state_time > 5000)
            {
                printf("---> goto kick1 <---\n");
                goto kick1;
            }
        }
        action
        {
            printf("# state = workToLeft1 #\n");
            WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), Pose2f(0.f, 0.f, 1250.f));
            theHeadControlMode = HeadControl::lookForward;
            // WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), AbsolutePointToRobot(theRobotPose, 2000.f, 0.f));
        }
    }
    
    state(kick1)
    {
        transition
        {
            if (state_time > KICK_TIME)
            {
                printf("---> goto tui1 <---\n");
                goto tui1;
            }
        }
        action
        {
            printf("# state = kick1 #\n");
            KickOnce();
        }
    }
    
    state(tui1)
    {
        transition
        {
            if(state_time > TUI_TIME)
            {
                printf("---> goto workToRight1 <---\n");
                goto workToRight1;
            }
        }
        action
        {
            printf("# state = tui1 #\n");
            theHeadControlMode = HeadControl::leftAndRight;
            WalkToTarget(TUI_SPEED, Pose2f(0_deg,-1000.f, 0.f));  
        }
    }
    
    state(workToRight1)
    {
        transition
        {
            if (state_time > WORKTOR_TIME)
            {
                printf("---> goto kick2 <---\n");
                goto kick2;
            }
        }
        action
        {
            printf("# state = workToRight #\n");
            WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), Pose2f(0.f, 0.f, TUI_LENGTH));
            // WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), AbsolutePointToRobot(theRobotPose, 2000.f, 0.f));
        }
    }
    
    state(kick2)
    {
        transition
        {
            if (state_time > KICK_TIME)
            {
                printf("---> goto tui2 <---\n");
                goto tui2;
            }
        }
        action
        {
            printf("# state = kick2 #\n");
            KickOnce();
        }
    }
    
    state(tui2)
    {
        transition
        {
            if(state_time > TUI_TIME)
            {
                printf("---> goto workToRight2 <---\n");
                goto workToRight2;
            }
        }
        action
        {
            printf("# state = tui2 #\n");
            theHeadControlMode = HeadControl::leftAndRight;
            WalkToTarget(TUI_SPEED, Pose2f(0_deg,-1000.f, 0.f));  
        }
    }
    
    state(workToRight2)
    {
        transition
        {
            if (state_time > WORKTOR_TIME)
            {
                printf("---> goto kick3 <---\n");
                goto kick3;
            }
        }
        action
        {
            printf("# state = workToRight2 #\n");
            WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), Pose2f(0.f, 0.f, TUI_LENGTH));
            // WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), AbsolutePointToRobot(theRobotPose, 2000.f, 0.f));
        }
    }
    
    state(kick3)
    {
        transition
        {
            if (state_time > KICK_TIME)
            {
                printf("---> goto stop <---\n");
                goto stop;
            }
        }
        action
        {
            printf("# state = kick3 #\n");
            KickOnce();
        }
    }
    
    state(stop)
    {
        transition
        {
            
        }
        action
        {
            Stand();
        }
    }
}