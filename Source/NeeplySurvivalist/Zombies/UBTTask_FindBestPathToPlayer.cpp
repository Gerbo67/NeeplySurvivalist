// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombies/UBTTask_FindBestPathToPlayer.h" // Asegúrate que la ruta sea correcta
#include "EnvironmentQuery/EnvQueryManager.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UUBTTask_FindBestPathToPlayer::UUBTTask_FindBestPathToPlayer()
{
	NodeName = "Find Best Path To Player";
}

EBTNodeResult::Type UUBTTask_FindBestPathToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	MyOwnerComp = &OwnerComp;

	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController || !FindPlayerQuery)
	{
		return EBTNodeResult::Failed;
	}

	QueryRequest = FEnvQueryRequest(FindPlayerQuery, AIController->GetPawn());
	QueryRequest.Execute(EEnvQueryRunMode::SingleResult, this, &UUBTTask_FindBestPathToPlayer::OnQueryFinished);

	return EBTNodeResult::InProgress;
}

void UUBTTask_FindBestPathToPlayer::OnQueryFinished(TSharedPtr<FEnvQueryResult> Result)
{
	if (Result->IsSuccessful() && Result->Items.Num() > 0)
	{
		const FVector BestLocation = Result->GetItemAsLocation(0);

		MyOwnerComp->GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), BestLocation);

		FinishLatentTask(*MyOwnerComp, EBTNodeResult::Succeeded);
	}
	else
	{
		FinishLatentTask(*MyOwnerComp, EBTNodeResult::Failed);
	}
}