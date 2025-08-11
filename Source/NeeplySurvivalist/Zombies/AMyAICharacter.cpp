#include "Zombies/AMyAICharacter.h"
#include "Zombies/AMyAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "AIController.h"
#include "BrainComponent.h"

#include "Engine/Engine.h"

#define PRINT_DAMAGE(msg) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, msg); }

AAMyAICharacter::AAMyAICharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AAMyAIController::StaticClass();
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 100.0f, 0.0f);
}

void AAMyAICharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AAMyAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAMyAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float AAMyAICharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
								  AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;
		PRINT_DAMAGE(FString::Printf(TEXT("Vida restante de %s: %f"), *GetName(), Health));

		if (Health <= 0.f && !bIsDying)
		{
			StartDeathSequence();
		}
	}

	return ActualDamage;
}

void AAMyAICharacter::StartDeathSequence()
{
	bIsDying = true;

	if (AAIController* AIController = Cast<AAIController>(GetController()))
	{
		AIController->GetBrainComponent()->StopLogic("Dead");
	}

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	GetCharacterMovement()->StopMovementImmediately();
	GetCharacterMovement()->DisableMovement();
	
	OnDeath();
}