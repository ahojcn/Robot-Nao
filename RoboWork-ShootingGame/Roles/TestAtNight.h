/** A test striker option without common decision */
option(TestAtNight)
{
  float she_X = -500.0f;
  //float she_X = 0.0f;
  float she_Y = 0.0f;
  float distance;
  initial_state(start)
  {
    transition
    {
      if(state_time > 10000)
        goto turnToBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      //WalkAtRelativeSpeed(Pose2f(1.f, 0.f, 0.f));
      Stand();
    }
  }

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
        goto alignToGoal;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), theBallModel.estimate.position);
    }
  }

    // AbsolutePointToRobot(theRobotPose, 2000.f, 3000.f).rotation.toDegrees()

  state(alignToGoal)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(/*std::abs(AbsolutePointToRobot(theRobotPose, 2000.f, 3000.f).rotation.toDegrees()) < 10_deg &&*/ std::abs(theBallModel.estimate.position.y()) < 100.f)
        goto alignBehindBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(100.f, 100.f, 100.f), Pose2f(AbsolutePointToRobot(theRobotPose, 3000.f, 4500.f).rotation.toDegrees(), theBallModel.estimate.position.x() - 350.f, theBallModel.estimate.position.y()));
    }
  }

  state(alignBehindBall)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(theLibCodeRelease.between(theBallModel.estimate.position.y(), 40.f, 70.f)
      && theLibCodeRelease.between(theBallModel.estimate.position.x(), 160.f, 220.f)
      /*&& std::abs(AbsolutePointToRobot(theRobotPose, 2000.f, 3000.f).rotation.toDegrees()) < 2_deg*/)
        goto kick;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(AbsolutePointToRobot(theRobotPose, 3000.f, 4500.f).rotation.toDegrees(), theBallModel.estimate.position.x() - 200.f, theBallModel.estimate.position.y() - 50.f));
    }
  }

  state(kick)
  {
    transition
    {
      if(state_time > 3000 )
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
            goto searchForBall;
    }
    action
    {
     theHeadControlMode = HeadControl::leftAndRight;
     WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(0_deg,-1000.f, 0.f));  
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
