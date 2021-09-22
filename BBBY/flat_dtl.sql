create materialized view bbby_views.orders_material as
SELECT 
    o.ord_id,
    o.ord_date,
    o.cust_id,
    o.ord_tot,
    o.cust_name,zip,
    flat_dtl.det_id,
    flat_dtl.item_id,
    flat_dtl.qty,
    flat_dtl.item_desc,
    flat_dtl.cost
FROM `anand-bq-test-2.bbby_data.orders` o 
cross join unnest(dtl) as flat_dtl