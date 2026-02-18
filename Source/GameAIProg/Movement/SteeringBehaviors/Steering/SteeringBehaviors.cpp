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

SteeringOutput Arrive::CalculateSteering(float DeltaT, ASteeringAgent& Agent)
{
	SteeringOutput steeringOutput{};
	const FVector2D agentpos{ Agent.GetPosition() };
	const FVector2D targetpos{ Target.Position };

	steeringOutput.LinearVelocity = targetpos - agentpos;



	if (steeringOutput.LinearVelocity.Length() <= Agent.GetTargetRadius())
	{
		steeringOutput.LinearVelocity = FVector2D{0,0};
	}
	else if (steeringOutput.LinearVelocity.Length() <= Agent.GetSlowRadius())
	{
		Agent.SetMaxLinearSpeed(50);
	}
	else
	{
		Agent.SetMaxLinearSpeed(100);
	}

	DrawDebugCircle(
		Agent.GetWorld(),
		FVector(agentpos.X, agentpos.Y, 1),
		Agent.GetSlowRadius(),
		16,
		FColor::Blue,
		false,
		-1.0f,
		0,
		1.0f,
		FVector(1, 0, 0),   // Y axis
		FVector(0, 1, 0),   // Z axis
		false
	);

	DrawDebugCircle(
		Agent.GetWorld(),
		FVector(agentpos.X, agentpos.Y, 1),
		Agent.GetTargetRadius(),
		16,
		FColor::Red,
		false,
		-1.0f,
		0,
		1.0f,
		FVector(1, 0, 0),   // Y axis
		FVector(0, 1, 0),   // Z axis
		false
	);



	return steeringOutput;
}
