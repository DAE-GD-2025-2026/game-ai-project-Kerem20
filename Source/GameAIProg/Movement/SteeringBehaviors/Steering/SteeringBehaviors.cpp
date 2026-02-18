#include "SteeringBehaviors.h"
#include "GameAIProg/Movement/SteeringBehaviors/SteeringAgent.h"

//SEEK
//*******
// TODO: Do the Week01 assignment :^)

SteeringOutput Seek::CalculateSteering(float DeltaT, ASteeringAgent& Agent)
{
	SteeringOutput steeringOutput{};
	const FVector2D agentpos{ Agent.GetPosition() };
	const FVector2D targetpos{ Target.Position };

	const float debugDirLine{250.f};

	steeringOutput.LinearVelocity = targetpos - agentpos;

	DrawDebugBox(Agent.GetWorld(),
		FVector{targetpos.X, targetpos.Y, 1},
		FVector{5,5,5},
		FColor::Red);

	return steeringOutput;
}

SteeringOutput Flee::CalculateSteering(float DeltaT, ASteeringAgent& Agent)
{
	SteeringOutput steeringOutput{};
	const FVector2D agentpos{ Agent.GetPosition() };
	const FVector2D targetpos{ Target.Position };

	steeringOutput.LinearVelocity = agentpos - targetpos;

	DrawDebugBox(Agent.GetWorld(),
		FVector{ targetpos.X, targetpos.Y, 1 },
		FVector{ 5,5,5 },
		FColor::Red);

	return steeringOutput;
}
