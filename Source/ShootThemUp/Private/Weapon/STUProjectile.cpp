// Shoot Them Up. All rights Reserved.

#include "Weapon/STUProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ASTUProjectile::ASTUProjectile()
{
    PrimaryActorTick.bCanEverTick = true;
    CollisionComponent = CreateDefaultSubobject<USphereComponent>("CollisionComponent");
    CollisionComponent->InitSphereRadius(5.0f);
    SetRootComponent(CollisionComponent);

    MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
    MovementComponent->InitialSpeed = 2000.0f;
    MovementComponent->ProjectileGravityScale = 0.0f;
}

void ASTUProjectile::BeginPlay()
{
    Super::BeginPlay();
    check(MovementComponent);
    MovementComponent->Velocity = ShotDirection * MovementComponent->InitialSpeed;
    SetLifeSpan(5.0f);
}
