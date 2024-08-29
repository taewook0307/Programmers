#include <string>
#include <vector>

class Health
{
public:
    Health(int _InitHp = 0, int _ConditionHealCount = 0, int _PlusHeal = 0)
        : Hp(_InitHp), MaxHp(_InitHp), ConditionHealCount(_ConditionHealCount), PlusHeal(_PlusHeal)
    {

    }

    void TakeDamage(int _DamageValue)
    {
        // 데미지 후 지금까지 힐한 횟수 초기화
        Hp -= _DamageValue;
        SuccessContinueHealCount = 0;
    }

    void Heal(int _HealValue)
    {
        // Hp가 0이면 무시
        if (Hp <= 0)
        {
            return;
        }

        ++SuccessContinueHealCount;

        // 일반 힐
        if (SuccessContinueHealCount != ConditionHealCount)
        {
            Hp += _HealValue;
        }
        // 추가 힐
        else
        {
            Hp += _HealValue;
            Hp += PlusHeal;
            SuccessContinueHealCount = 0;
        }

        // Max 값 초과 시
        if (Hp > MaxHp)
        {
            Hp = MaxHp;
        }
    }

    int GetHp() const
    {
        return Hp <= 0 ? -1 : Hp;
    }

private:
    int Hp = 0;                             // 현재 Hp
    int MaxHp = 0;                          // 최대 Hp

    int SuccessContinueHealCount = 0;       // 힐은 연속한 횟수
    int ConditionHealCount = 0;             // 추가 힐 조건 횟수
    int PlusHeal = 0;                       // 추가 힐 량
};

int solution(std::vector<int> bandage, int health, std::vector<std::vector<int>> attacks)
{
    Health Stat = Health(health, bandage[0], bandage[2]);

    // 공격 횟수
    const int AttackCount = static_cast<int>(attacks.size());
    // 마지막 공격 시간
    const int LastAttackTime = attacks[AttackCount - 1][0];

    // 진행예정된 공격의 인덱스 값
    int CheckAttackIndex = 0;

    for (int i = 1; i <= LastAttackTime; ++i)
    {
        // 진행되야하는 공격 시간
        int CurAttackTime = attacks[CheckAttackIndex][0];

        if (CurAttackTime == i)
        {
            int CurAttackDamage = attacks[CheckAttackIndex][1];

            // Damage
            Stat.TakeDamage(CurAttackDamage);
            ++CheckAttackIndex;
        }
        else
        {
            // Heal
            Stat.Heal(bandage[1]);
        }   
    }

    return Stat.GetHp();
}
