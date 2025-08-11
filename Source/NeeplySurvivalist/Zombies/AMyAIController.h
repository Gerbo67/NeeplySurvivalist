#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AMyAIController.generated.h"

// Declaraciones anticipadas para buena práctica y compilación más rápida
class UBehaviorTree;
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class NEEPLYSURVIVALIST_API AAMyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AAMyAIController();

protected:
	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

	UPROPERTY()
	TObjectPtr<UBlackboardComponent> BlackboardComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTreeAsset;
	
	virtual void OnPossess(APawn* InPawn) override;
	
	virtual void Tick(float DeltaTime) override;
};