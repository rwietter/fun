## String Data Types

**CHAR(size)**:	a FIXED length string (can contain letters, numbers, and special characters). The size parameter specifies the column length in characters - can be from 0 to 255. Default is 1

**VARCHAR(size)**: a VARIABLE length string (can contain letters, numbers, and special characters). The size parameter specifies the maximum string length in characters - can be from 0 to 65535

**BINARY(size)**: equal to CHAR(), but stores binary byte strings. The size parameter specifies the column length in bytes. Default is 1

**VARBINARY(size)**: equal to VARCHAR(), but stores binary byte strings. The size parameter specifies the maximum column length in bytes.

**TINYBLOB**: for BLOBs (Binary Large Objects). Max length: 255 bytes

**TINYTEXT:** holds a string with a maximum length of 255 characters

**TEXT(size)**: holds a string with a maximum length of 65,535 bytes

**BLOB(size)**: for BLOBs (Binary Large Objects). Holds up to 65,535 bytes of data

**MEDIUMTEXT**: holds a string with a maximum length of 16,777,215 characters

**MEDIUMBLOB**: for BLOBs (Binary Large Objects). Holds up to 16,777,215 bytes of data

**LONGTEXT**: holds a string with a maximum length of 4,294,967,295 characters

**LONGBLOB**: for BLOBs (Binary Large Objects). Holds up to 4,294,967,295 bytes of data

**ENUM(val1, val2, val3, ...)**: a string object that can have only one value, chosen from a list of possible values. You can list up to 65535 values in an ENUM list. If a value is inserted that is not in the list, a blank value will be inserted. The values are sorted in the order you enter them

**SET(val1, val2, val3, ...)**: a string object that can have 0 or more values, chosen from a list of possible values. You can list up to 64 values in a SET list

---

## Numeric Data Types

**BIT(size)**: a bit-value type. The number of bits per value is specified in size. The size parameter can hold a value from 1 to 64. The default value for size is 1.

**TINYINT(size)**: a very small integer. Signed range is from -128 to 127. Unsigned range is from 0 to 255. The size parameter specifies the maximum display width (which is 255)

**BOOL**: zero is considered as false, nonzero values are considered as true.

**BOOLEAN**: equal to BOOL

**SMALLINT(size)**:	a small integer. Signed range is from -32768 to 32767. Unsigned range is from 0 to 65535. The size parameter specifies the maximum display width (which is 255)

**MEDIUMINT(size)**: a medium integer. Signed range is from -8388608 to 8388607. Unsigned range is from 0 to 16777215. The size parameter specifies the maximum display width (which is 255)

**INT(size)**: a medium integer. Signed range is from -2147483648 to 2147483647. Unsigned range is from 0 to 4294967295. The size parameter specifies the maximum display width (which is 255)

**INTEGER(size)**: equal to INT(size)

**BIGINT(size)**: a large integer. Signed range is from -9223372036854775808 to 9223372036854775807. Unsigned range is from 0 to 18446744073709551615. The size parameter specifies the maximum display width (which is 255)

**FLOAT(size, d)**:	a floating point number. The total number of digits is specified in size. The number of digits after the decimal point is specified in the d parameter. This syntax is deprecated in MySQL 8.0.17, and it will be removed in future MySQL versions

**FLOAT(p)**: a floating point number. MySQL uses the p value to determine whether to use FLOAT or DOUBLE for the resulting data type. If p is from 0 to 24, the data type becomes FLOAT(). If p is from 25 to 53, the data type becomes DOUBLE()

**DOUBLE(size, d)**: a normal-size floating point number. The total number of digits is specified in size. The number of digits after the decimal point is specified in the d parameter

**DECIMAL(size, d)**: an exact fixed-point number. The total number of digits is specified in size. The number of digits after the decimal point is specified in the d parameter. The maximum number for size is 65. The maximum number for d is 30. The default value for size is 10. The default value for d is 0.

**DEC(size, d)**: equal to DECIMAL(size,d)

---

## Date and Time Data Types

**DATE**: a date. Format: YYYY-MM-DD. The supported range is from '1000-01-01' to '9999-12-31'

**DATETIME(fsp)**: a date and time combination. Format: YYYY-MM-DD hh:mm:ss. The supported range is from '1000-01-01 00:00:00' to '9999-12-31 23:59:59'. Adding DEFAULT and ON UPDATE in the column definition to get automatic initialization and updating to the current date and time

**TIMESTAMP(fsp)**:	a timestamp. TIMESTAMP values are stored as the number of seconds since the Unix epoch ('1970-01-01 00:00:00' UTC). Format: YYYY-MM-DD hh:mm:ss. The supported range is from '1970-01-01 00:00:01' UTC to '2038-01-09 03:14:07' UTC. Automatic initialization and updating to the current date and time can be specified using DEFAULT CURRENT_TIMESTAMP and ON UPDATE CURRENT_TIMESTAMP in the column definition

**TIME(fsp)**: a time. Format: hh:mm:ss. The supported range is from '-838:59:59' to '838:59:59'

**YEAR**: a year in four-digit format. Values allowed in four-digit format: 1901 to 2155, and 0000. MySQL 8.0 does not support year in two-digit format.

---

### Bit Numerical Types

| Data type  |  Range       |                            | Storage |
| -----------|--------------|----------------------------|-------- |
| bigint     | 2^63 | 2^63-1 (9,223,372,036,854,775,807) | 8 Bytes |
| int        | -2^31 | 2^31-1 (2,147,483,647)            | 4 Bytes |
| smallint   | -2^15 | 2^15-1 (32,767)                   | 2 Bytes |
| tinyint    | 0 to 255                                  | 1 Byte  |
