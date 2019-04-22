/** All option files that belong to the current behavior have to be included by this file. */

#include "Options/Soccer.h"


#include "Options/GameControl/SetState.h"
#include "Options/GameControl/HandleGameState.h"
#include "Options/GameControl/HandlePenaltyState.h"
#include "Options/GameControl/PlayingState.h"
#include "Options/GameControl/ReadyState.h"


#include "Options/HeadControl/LeftAndRight.h"


#include "Options/HeadControl/HeadControl.h"

#include "Options/HeadControl/SearchForBall.h"
#include "Options/HeadControl/keeperSearchForBall.h"
#include "Options/HeadControl/LookForward.h"

#include "Options/Output/Activity.h"
#include "Options/Output/Annotation.h"

#include "Options/Output/HeadMotionRequest/SetHeadPanTilt.h"
#include "Options/Output/HeadMotionRequest/SetHeadTarget.h"


#include "Options/Output/MotionRequest/InWalkKick.h"
#include "Options/Output/MotionRequest/SpecialAction.h"
#include "Options/Output/MotionRequest/Stand.h"
#include "Options/Output/MotionRequest/WalkAtAbsoluteSpeed.h"
#include "Options/Output/MotionRequest/WalkAtRelativeSpeed.h"
#include "Options/Output/MotionRequest/WalkToTarget.h"
#include "Options/Output/MotionRequest/GetUpEngine.h"
#include "Options/Output/MotionRequest/middelSideDown.h"
#include "Options/Output/MotionRequest/rightSideDown.h"
#include "Options/Output/MotionRequest/leftSideDown.h"
#include "Options/Output/MotionRequest/KickForWard.h"
#include "Options/Output/PlaySound.h"

#include "Options/Roles/Striker.h"
#include "Options/Roles/Keeper.h"
#include "Options/Roles/Supporter.h"
#include "Options/Roles/Defender_2.h"
#include "Options/Roles/Defender_1.h"

#include "Options/Roles/KickOnce.h" // kick 1 ball
#include "Options/Roles/ThreeBalls.h" // kick 3 balls
#include "Options/Roles/FiveBalls.h" // kick 5 balls
#include "Options/Roles/ahojTest.h" // kick 7 balls

#include "Options/Roles/TestAtNight.h"

#include "Options/Skills/GetUp.h"

#include "Options/DemoOptions/Demo.h"
#include "Options/DemoOptions/Waving.h"

#include "Options/Tools/ButtonPressedAndReleased.h"