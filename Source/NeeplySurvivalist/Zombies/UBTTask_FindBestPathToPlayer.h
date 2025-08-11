// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "UBTTask_FindBestPathToPlayer.generated.h"

UCLASS()
class NEEPLYSURVIVALIST_API UUBTTask_FindBestPathToPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UUBTTask_FindBestPathToPlayer();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = "AI")
	class UEnvQuery* FindPlayerQuery;

private:
	void OnQueryFinished(TSharedPtr<FEnvQueryResult> Result);

	UPROPERTY()
	FEnvQueryRequest QueryRequest;
	
	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> MyOwnerComp;
};