/*
 * 踢一个球
 *      1. 走近球
        2. 脚对准球
        3. kick
 */
option(KickOnce)
{
  float she_X = -500.0f;
  //float she_X = 0.0f;
  float she_Y = 0.0f;
  float distance;
  initial_state(start)
  {
    transition
    {
      //if(state_time > 15000)
       // goto turnToBall;
       goto walkToBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      //WalkAtRelativeSpeed(Pose2f(1.f, 0.f, 0.f));
      Stand();
    }
  }

///////////////////////////////////
  state(turnToBall)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(std::abs(theBallModel.estimate.position.angle()) < 5_deg)
        goto walkToBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
    }
  }

  state(walkToBall)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(theBallModel.estimate.position.norm() < 500.f)
        goto alignBehindBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), theBallModel.estimate.position);
    }
  }

//  state(alignToGoal)
//  {
//    transition
//    {
//      if(theLibCodeRelease.timeSinceBallWasSeen > theBehaviorParameters.ballNotSeenTimeOut)
//        goto searchForBall;
//      if(std::abs(theLibCodeRelease.angleToOwnGoal+90) < 10_deg && std::abs(theBallModel.estimate.position.y()) < 100.f)
//        goto alignBehindBall;
//    }
//    action
//    {
//      theHeadControlMode = HeadControl::lookForward;
//      WalkToTarget(Pose2f(100.f, 100.f, 100.f), Pose2f(theLibCodeRelease.angleToOwnGoal+90, theBallModel.estimate.position.x() - 350.f, theBallModel.estimate.position.y()));
//    }
//  }

  state(alignBehindBall)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(theLibCodeRelease.between(theBallModel.estimate.position.y(), 40.f, 70.f)
      && theLibCodeRelease.between(theBallModel.estimate.position.x(), 160.f, 220.f))
     //&& std::abs(theLibCodeRelease.angleToOwnGoal) < 2_deg)
        goto kick;
    }
    action
    {
      theHeadControlMode = HeadControl::focusBall;
      // WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(theLibCodeRelease.angleToOwnGoal, theBallModel.estimate.position.x() - 200.f, theBallModel.estimate.position.y() - 50.f));
      WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(0.f, theBallModel.estimate.position.x() - 200.f, theBallModel.estimate.position.y() - 50.f));
    }
  }

  state(kick)
  {
    transition
    {
      if(state_time > 5000)
        goto tui;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      KickForWard(KickRequest::kickForward,true);
      //InWalkKick(WalkKickVariant(WalkKicks::forward, Legs::left), Pose2f(theLibCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 160.f, theBallModel.estimate.position.y() - 55.f));
    }
  }
  
  state(tui)
  {
    transition
    {
        if(state_time > 5000)
            goto kickEnd;
            // goto searchForBall;
            // Stand();
    }
    action
    {
        theHeadControlMode = HeadControl::leftAndRight;
        WalkToTarget(Pose2f(30.f, 30.f, 30.f), Pose2f(0_deg,-550.f, 0.f));  
    }
  }
  
  state(kickEnd)
  {
      transition
      {
          
      }
      action
      {
          theHeadControlMode = HeadControl::lookForward;
          Stand();
      }
  }
  
  state(searchForBall)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen < 300)
        goto standMiddel;
    }
    action
    {
      theHeadControlMode = HeadControl::leftAndRight;
      WalkAtRelativeSpeed(Pose2f(1.f, 0.f, 0.f));
    }
  }
  
  state(standMiddel)
  {
    transition
    {
        Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,she_X,she_Y);
           distance = relatePoint.translation.norm();
           if ( distance < 10.0 )
           goto searchForBall;
           if(theLibCodeRelease.timeSinceBallWasSeen < 300)
               goto turnToBall;
    }
    action
    {
        LeftAndRight();
          Pose2f relatePoint=AbsolutePointToRobot(theRobotPose,she_X,she_Y);
          WalkToTarget(Pose2f(pi/8,50.f,50.f),relatePoint);
    }
  }
}
