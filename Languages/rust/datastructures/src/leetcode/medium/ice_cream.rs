/**
 * 1833. Maximum Ice Cream Bars <https://leetcode.com/problems/maximum-ice-cream-bars/>
 */

struct IceCream {
    costs: Vec<i32>,
    coins: i32,
}

impl IceCream {
    fn max_ice_cream(costs: Vec<i32>, coins: i32) -> i32 {
        let mut sorted_costs = costs;
        sorted_costs.sort();

        let (total_ice_creams, _) =
            sorted_costs
                .iter()
                .fold((0, coins), |(mut total, remaining_coins), &cost| {
                    if cost <= remaining_coins {
                        total += 1;
                        return (total, remaining_coins - cost);
                    }
                    (total, remaining_coins)
                });
        total_ice_creams
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_ice_cream() {
        assert_eq!(IceCream::max_ice_cream(vec![1, 3, 2, 4, 1], 7), 4);
        assert_eq!(IceCream::max_ice_cream(vec![10, 6, 8, 7, 7, 8], 5), 0);
        assert_eq!(IceCream::max_ice_cream(vec![1, 6, 3, 1, 2, 5], 20), 6);
    }
}

pub fn ice_cream() {
    let ice = IceCream {
        coins: 7,
        costs: vec![1, 3, 2, 4, 1],
    };

    println!(
        "max_ice_cream: {}",
        IceCream::max_ice_cream(ice.costs, ice.coins)
    );
}
