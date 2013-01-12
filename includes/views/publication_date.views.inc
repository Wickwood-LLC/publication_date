<?php
// $Id: $

/**
 * @file
 * Provide views data and handlers for publication_date.module
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */

/**
 * Implements hook_views_data()
 */
function publication_date_views_data() {
  $data = array();

  $data['publication_date']['table']['group'] = t('Content');

  // how is the scheduler table linked to the nodes
  $data['publication_date']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );

  // description of the fields (columns)
  $data['publication_date']['published_at'] = array(
    'title' => t('Published at'),
    'help' => t('Date and time on which the article has been published.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
      'label' => t('Published at'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  // Bogus fields for aliasing purposes.

  $data['publication_date']['published_at_fulldate'] = array(
    'title' => t('Published date'),
    'help' => t('Date in the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'published_at',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  $data['publication_date']['published_at_year_month'] = array(
    'title' => t('Published year + month'),
    'help' => t('Date in the form of YYYYMM.'),
    'argument' => array(
      'field' => 'published_at',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  $data['publication_date']['published_at_year'] = array(
    'title' => t('Published year'),
    'help' => t('Date in the form of YYYY.'),
    'argument' => array(
      'field' => 'published_at',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  $data['publication_date']['published_at_month'] = array(
    'title' => t('Published month'),
    'help' => t('Date in the form of MM (01 - 12).'),
    'argument' => array(
      'field' => 'published_at',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  $data['publication_date']['published_at_day'] = array(
    'title' => t('Published day'),
    'help' => t('Date in the form of DD (01 - 31).'),
    'argument' => array(
      'field' => 'published_at',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  $data['publication_date']['published_at_week'] = array(
    'title' => t('Published week'),
    'help' => t('Date in the form of WW (01 - 53).'),
    'argument' => array(
      'field' => 'published_at',
      'handler' => 'views_handler_argument_node_created_week',
    ),
  );

  return $data;
}
