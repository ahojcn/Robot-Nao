/*
 * kick 5 balls 
 */

#define TUI_SPEED Pose2f(80.f, 80.f, 80.f)
#define TUI_TIME 6000

#define WORKTOR_TIME5 5500
 
option(FiveBalls)
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
    
    /////////////////////////////////////////
    
    state(workToLeft1)
    {
        transition
        {
            if (state_time > 11000)
            {
                printf("---> goto kick1 <---\n");
                goto kick1;
            }
        }
        action
        {
            printf("# state = workToLeft1 #\n");            
            theHeadControlMode = HeadControl::lookRight;
            WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), Pose2f(0.f, 0.f, 2000.f));
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
    
    /////////////////////////////////////////
    
    state(workToRight1)
    {
        transition
        {
            if (state_time > WORKTOR_TIME5)
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
    
    /////////////////////////////////////////
    
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
            if (state_time > WORKTOR_TIME5)
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
                printf("---> goto tui3 <---\n");
                goto tui3;
            }
        }
        action
        {
            printf("# state = kick3 #\n");
            KickOnce();
        }
    }
    
    state(tui3)
    {
        transition
        {
            if(state_time > TUI_TIME)
            {
                printf("---> goto workToRight3 <---\n");
                goto workToRight3;
            }
        }
        action
        {
            printf("# state = tui3 #\n");
            theHeadControlMode = HeadControl::leftAndRight;
            WalkToTarget(TUI_SPEED, Pose2f(0_deg,-1000.f, 0.f));  
        }
    }
    
    /////////////////////////////////////////
    
    state(workToRight3)
    {
        transition
        {
            if (state_time > WORKTOR_TIME5)
            {
                printf("---> goto kick3 <---\n");
                goto kick4;
            }
        }
        action
        {
            printf("# state = workToRight3 #\n");
            WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), Pose2f(0.f, 0.f, TUI_LENGTH));
            // WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), AbsolutePointToRobot(theRobotPose, 2000.f, 0.f));
        }
    }
    
    state(kick4)
    {
        transition
        {
            if (state_time > KICK_TIME)
            {
                printf("---> goto stop <---\n");
                goto tui4;
            }
        }
        action
        {
            printf("# state = kick4 #\n");
            KickOnce();
        }
    }
    
    state(tui4)
    {
        transition
        {
            if(state_time > TUI_TIME)
            {
                printf("---> goto workToRight4 <---\n");
                goto workToRight4;
            }
        }
        action
        {
            printf("# state = tui4 #\n");
            theHeadControlMode = HeadControl::leftAndRight;
            WalkToTarget(TUI_SPEED, Pose2f(0_deg,-1000.f, 0.f));  
        }
    }
    
    /////////////////////////////////////////
    
    state(workToRight4)
    {
        transition
        {
            if (state_time > WORKTOR_TIME5)
            {
                printf("---> goto kick5 <---\n");
                goto kick5;
            }
        }
        action
        {
            printf("# state = workToRight4 #\n");
            WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), Pose2f(0.f, 0.f, TUI_LENGTH));
            // WalkToTarget(Pose2f(50.0f, 50.0f, 50.f), AbsolutePointToRobot(theRobotPose, 2000.f, 0.f));
        }
    }
    
    state(kick5)
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
            printf("# state = kick5 #\n");
            KickOnce();
        }
    }
    
    /////////////////////////////////////////
    
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