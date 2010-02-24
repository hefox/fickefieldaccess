<?php


function taxonomyfieldaccess_admin() {
  $form = array();
  _form_fickle_types($form,'taxonomyfieldaccess_types');
  _form_fickle_sadresponses($form,'taxonomyfieldaccess_sadresponses');
  _form_fickle_skip_access($form,'taxonomyfieldaccess_skip_access');
  _form_fickle_ops($form,'taxonomyfieldaccess_ops');
    $vocabularies = taxonomy_get_vocabularies();
  $options = array();
  foreach ($vocabularies as $voc) {
    $options[$voc->vid] = $voc->name;
  }
  $form['taxonomyfieldaccess_method'] = array(
    '#type'=>'radios',
    '#options'=>array('vocab'=>'Vocabulary','term'=>'Terms'),
    '#default_value'=>variable_get('taxonomyfieldaccess_method','term'),
    '#title'=>t('Method'),
    '#description'=>t("Method vocabulary will control access based on if a node has any terms from that vocabulary. Method term will control whether based on if node is tagged with a set of terms."),
  );
  $form['taxonomyfieldaccess_vocabs'] = array(
    '#type'=>'checkboxes',
    '#options'=> $options,
    '#default_value'=> variable_get('taxonomyfieldaccess_vocabs',array()),
    '#multiple'=>1,
    '#title'=>t('Vocabularies'),
    '#description'=>t("For method vocabulary, it will control what vocabularies are considered. "),
  );
  return system_settings_form($form);
}