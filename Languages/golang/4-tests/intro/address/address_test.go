package address_test

import (
	"address/address"
	"testing"
)

type addressTypeTest struct {
	address  string
	expected string
}

func TestAddressType(t *testing.T) {
	t.Parallel()
	t.Run("should return 'Rua' when address is 'Rua 1'", func(t *testing.T) {

		tests := []addressTypeTest{
			{"Rua 1", "Rua"},
			{"Avenida 2", "Avenida"},
			{"Estrada 3", "Estrada"},
			{"Rodovia 4", "Rodovia"},
			{"", "Invalid"},
		}

		for _, test := range tests {
			addressType := address.AddressType(test.address)

			if addressType != test.expected {
				t.Errorf("expected '%s', got %s", test.expected, addressType)
			}
		}
	})
}
