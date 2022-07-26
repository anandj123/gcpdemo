/*

To create the destination table you could use the following;

create or replace table `anand-bq-test-2.hca_test.TextTableAgg` as 
select 
  count(*) total_records,
  CURRENT_TIMESTAMP() as create_time 
from `anand-bq-test-2.hca_test.TextTable`;


*/

create procedure `anand-bq-test-2.hca_test.demo_proc` ()
BEGIN
  insert into `anand-bq-test-2.hca_test.TextTableAgg` 
  select 
    count(*) total_records,
    CURRENT_TIMESTAMP() as create_time 
  from `anand-bq-test-2.hca_test.TextTable`;
END
