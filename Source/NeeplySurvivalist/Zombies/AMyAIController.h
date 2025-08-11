#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "AMyAIController.generated.h"

UCLASS()
class NEEPLYSURVIVALIST_API AAMyAIController : public AAIController {
	GENERATED_BODY()
public:
	AAMyAIController();
protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY()
	TObjectPtr<class UBehaviorTreeComponent> BehaviorTreeComponent;
	UPROPERTY()
	TObjectPtr<class UBlackboardComponent> BlackboardComponent;
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI")
	TObjectPtr<class UBehaviorTree> BehaviorTreeAsset;
};