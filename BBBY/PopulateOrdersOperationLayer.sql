CREATE OR REPLACE PROCEDURE `anand-bq-test-2.bbby_data.PopulateOrdersOperationLayer`()
BEGIN
  MERGE `anand-bq-test-2.bbby_data.orders` T
  USING (select 
      hdr.*,cust.cust_name,cust.zip,
      array(select as struct dtl.*,items.item_desc, items.cost 
              from `anand-bq-test-2.bbby_data.ord_dtl` dtl 
              inner join `anand-bq-test-2.bbby_data.items` items on dtl.item_id = items.item_id
              where hdr.ord_id = dtl.ord_id) as dtl
  from `anand-bq-test-2.bbby_data.ord_hdr` hdr
  inner join `anand-bq-test-2.bbby_data.cust` cust on hdr.cust_id = cust.cust_id)  S
  ON T.ord_id = S.ord_id
  WHEN NOT MATCHED THEN INSERT (ord_id,ord_date,cust_id,ord_tot,cust_name,zip,dtl) VALUES (ord_id,ord_date,cust_id,ord_tot,cust_name,zip,dtl)
  WHEN MATCHED THEN UPDATE SET 
      ord_id=S.ord_id, 
      ord_date=S.ord_date,
      cust_id=S.cust_id,
      ord_tot=S.ord_tot,
      cust_name=S.cust_name,
      zip=S.zip,
      dtl=S.dtl;
END;